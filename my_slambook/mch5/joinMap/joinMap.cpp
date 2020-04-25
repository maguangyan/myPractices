#include<iostream>
#include<fstream>
using namespace std;

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<eigen3/Eigen/Geometry>
#include<boost/format.hpp> //for formating string
#include<pcl/point_types.h>
#include<pcl/io/pcd_io.h>
#include<pcl/visualization/pcl_visualizer.h>

int main (int argc, char** argv)
{
    vector<cv::Mat> colorImgs, depthImges;//彩色图和深度图 使用了容器存放
    vector<Eigen::Isometry3d, Eigen::aligned_allocator<Eigen::Isometry3d>> poses;
    //相机位姿
    ifstream fin("./pose.txt");
    if (!fin)
    {
        cerr<<"请在有pose.txt的目录下运行此程序"<<endl;
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        boost::format fmt("./%s/%d.%s");//图像文件格式
        //将读取到color数据和depth 写如容器
        colorImgs.push_back(cv::imread((fmt%"color"%(i+1)%"png").str()));
        depthImges.push_back(cv::imread((fmt%"depth"%(i+1)%"pgm").str(),-1));//读取原始图像
        double data[7] = {0};
        for (auto& d:data)//auto 自动类型转换
        {
            /* code */
            fin>>d;
        }
        Eigen::Quaterniond q(data[6],data[3],data[4],data[5]);
        Eigen::Isometry3d T(q);//变换矩阵初始化旋转部分
        T.pretranslate(Eigen::Vector3d(data[0],data[1],data[2]));//初始化平移部分
        poses.push_back(T);//将位姿放入容器poses
        
    }
    //计算点云并拼接
    //相机内参
    double cx = 325.5;
    double cy = 253.5;
    double fx = 518.0;
    double fy = 519.0;
    double depthScale = 1000.0;

    cout<<"正在将图像转换为点云……"<<endl;
    //定义点云使用的格式，这里用的是XYZRGB
    typedef pcl::PointXYZRGB PointT;
    typedef pcl::PointCloud<PointT> PointCloud;

    //新建一个点云
    PointCloud::Ptr pointCloud(new PointCloud);
    for (int i = 0; i < 5; i++)
    {
        cout<<"转换图像中："<<i+1<<endl;
        cv::Mat color = colorImgs[i];
        cv::Mat depth = depthImges[i];
        Eigen::Isometry3d T = poses[i];//第i张图片的位姿 即此时Pwc
        for (int v = 0; v < color.rows; v++)
        {
            for (int u = 0; u < color.cols; u++)
            {
                uint d = depth.ptr<ushort>(v)[u];//读第(v,u)处像素值的深度值
                if (d==0) continue;//为0表示没有测量到  结束本次循环
                Eigen::Vector3d point;//接下来把像素坐标转换为相机坐标
                point[2] = double(d)/depthScale;//归一化
                point[0] = (u-cx)*point[2]/fx;
                point[1] = (v-cy)*point[2]/fy;
                Eigen::Vector3d pointWorld = T*point;//将相机坐标转换为世界坐标
 
                PointT p;
                p.x = pointWorld[0];
                p.y = pointWorld[1];
                p.z = pointWorld[2];
                /* cout<<color.step<<endl;1920
                cout<<color.step[0]<<endl;1920  一行所占的字节数
                cout<<color.step[1]<<endl;3 一个元素所占的字节数 1920/480=3
                cout<<color.step[2]<<endl;9713958914 于对于二维step只有两个维度 */
                p.b = color.data[v*color.step+u*color.channels()];
                p.g = color.data[v*color.step+u*color.channels()+1];
                p.r = color.data[v*color.step+u*color.channels()+2];
                pointCloud->points.push_back(p);
                
            }
            
        }
        
    }
    pointCloud->is_dense = false;
    cout<<"点云共有"<<pointCloud->size()<<"个点。"<<endl;
    pcl::io::savePCDFileBinary("map.pcd",*pointCloud);

   
    return 0;

}