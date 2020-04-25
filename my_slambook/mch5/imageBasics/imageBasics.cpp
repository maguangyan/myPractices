#include<iostream>
#include<chrono>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
int main(int argc, char** argv)
{
   cv::Mat image;
   image = cv::imread(argv[1]);
   if (image.data== nullptr)
   {
       cerr<<"文件"<<argv[1]<<"不存在"<<endl;
       return 0;
   }

   cout<<"图像宽为："<<image.cols<<",高为："<<image.rows<<",通道数为："<< image.channels()<<endl;

   cv::imshow("image", image);
   cv::waitKey(0);//暂停程序，等待一个按键输入
   //判断image类型
   if (image.type()!= CV_8UC1&& image.type()!=CV_8UC3)
   {
       //如果输入的不是8位单通道和8位3通道的图片
       cout<<"请输入一张彩色或灰度图"<<endl;
       return 0;//程序结束
   }
   //遍历图像 计时
   chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    for (size_t y = 0; y < image.rows; y++)
    {
        for (size_t x = 0; x < image.cols; x++)
        {
            //访问位于i j 处的像素
            uchar* row_ptr = image.ptr<uchar>(y);//指向第y行头指针(第y行第1个元素的指针)
            uchar* data_ptr = &row_ptr[x*image.channels()];//指向待访问的像素数据
            //即第y行的第x(假设通道为1)个元素的灰度值  ptr()[] 返回的不是指针了！！！而是一个数据！！！
            //输出该图像的每个通道
            for (int c = 0; c!=image.channels(); c++)
            {
                uchar data = data_ptr[c];//data为I（x,y)的第c通道的值
            }

            
        }
        
    }
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = 
    chrono::duration_cast<chrono::duration<double>>(t2 -t1);
    cout<<"遍历图像用时："<<time_used.count()<<"秒"<<endl;

    //关于cv::Mat 的拷贝 直接复制并不会复制数据
    cv::Mat image_another = image;
    //修改image_another 会改变image
    image_another(cv::Rect(0,0,100,100)).setTo(0);//将左上角一小块置0
    cv::namedWindow("after image_another");
    cv::imshow("after image_another",image);
    cv::waitKey(0);

    //使用clon函数来复制数据
    cv::Mat image_clone = image.clone();
    image_clone(cv::Rect(0,0,100,100)).setTo(255);
    cv::namedWindow("after image_clone");
    cv::imshow("after image_clone",image);
    cv::namedWindow("image_clone");
    cv::imshow("image_clone",image_clone);

    cv::waitKey('q');
   

    




    return 0;
}