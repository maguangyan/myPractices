#include <iostream>
#include<cmath>
using namespace std;

#include<Eigen/Core>
#include<Eigen/Geometry>

#include "sophus/so3.h" //引入头文件 特殊正交群
#include "sophus/se3.h"//特殊欧氏群




int main(int argc, char** argv)
{
   //沿Z轴转90度的旋转矩阵
   Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2,Eigen::Vector3d(0, 0, 1)).toRotationMatrix();
     
   Sophus::SO3 SO3_R(R);//构造一个SO3
   Sophus::SO3 SO3_v(0,0,M_PI/2);//直接从旋转向量构造SO3
   Eigen::Quaterniond q(R);//将R 转换为四元数
   Sophus::SO3 SO3_q(q);//直接从四元数构造 SO3

   cout<<"from matrix:\n"<<SO3_R<<endl;
   cout<<"from vector:\n"<<SO3_v<<endl;
   cout<<"from quaternion:\n"<<SO3_q<<endl;
    //使用对数映射获取他们的李代数
    Eigen::Vector3d  so3 = SO3_R.log();
    cout<<"so3 is:\n"<<so3.transpose()<<endl;

    cout<<"so3 hat is:\n"<<Sophus::SO3::hat(so3)<<endl;//向量到反对称矩阵
    cout<<"so3 vee is:\n"<<Sophus::SO3::vee(Sophus::SO3::hat(so3))<<endl;//反对称到向量

    //增量扰动模型的更新
    Eigen::Vector3d update_so3(1e-4,0,0);//假设更新量有这么多 微小扰动量
    Sophus::SO3 SO3_updated = Sophus::SO3::exp(update_so3)*SO3_R;//左乘更新
    // 对SO3进行更新
    cout<<"so3 updated=\n"<<SO3_updated<<endl;

    cout<<"*********分割线**********"<<endl;
    //对SE3大同小异
    Eigen::Vector3d t(1,0,0);//沿x轴平移1
    Sophus::SE3 SE3_Rt(R,t);//从Rt构造ＳE3
    cout<<"SE3 form R t:\n"<<SE3_Rt<<endl;
    Sophus::SE3 SE3_qt(q,t);//从四元数构造ＳＥ3
    cout<<"SE3 from q,t"<<SE3_qt<<endl;

    //使用typedef 搞一个别名 方便
    typedef Eigen::Matrix<double, 6,1> Vector6d;
    Vector6d se3 = SE3_Rt.log();
    cout<<"se3 is :\n"<<se3.transpose()<<endl;

    //hat vee
    cout<<"se3 hat is:\n"<<Sophus::SE3::hat(se3)<<endl;
    cout<<"se3 hat vee is:\n"<<Sophus::SE3::vee(Sophus::SE3::hat(se3))<<endl;

    //更新
    Vector6d update_se3;//更新量
    update_so3.setZero();
    update_so3(0,0) = 1e-4;

    Sophus::SE3 SE3_updated = Sophus::SE3::exp(update_se3)*SE3_Rt;
    cout<<"SE3 updated is:\n"<<SE3_updated.matrix()<<endl;



    return 0;
}
