#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

using namespace std;

int main (int argc, char** argv)
{
    // 初始化

    // 旋转向量（轴角）：沿z轴旋转45°
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1));
    cout<<"rotation_vector axis=\n"<<rotation_vector.axis()<<endl;
    cout<<"rotation_vector angles\n"<<rotation_vector.angle()<<endl;

    // 旋转矩阵： 沿z轴旋转45°
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    rotation_matrix<<
        0.707, -0.707, 0,
        0.707,  0.707, 0,
        0,      0,     1;
    cout<<"rotation matrix=\n"<<rotation_matrix<<endl;

    // 四元数： 沿z轴旋转45度
    Eigen::Quaterniond quat = Eigen::Quaterniond(0,0,0.383,0.924);  // 赋值方式为（w,x,y,z）
    cout<<"四元数输出方式1：quaternion=\n"<<quat.coeffs()<<endl;    // 输出方式为（x,y,z,w）
    cout<<"四元数输出方式2：\tw="<<quat.w()<<"\tx="<<quat.x()
        <<"\ty="<<quat.y()<<"\tz="<<quat.z()<<endl;
    
    // 欧拉角： 沿z轴旋转45°
    Eigen::Vector3d euler_angles = Eigen::Vector3d(M_PI/4,0,0);// zyx顺序即roll pitch yaw顺序
    cout<<"Euler:yaw pitch roll="<<euler_angles.transpose()<<endl;

    // 相互转换关系
    
    // 旋转向量转化为其他形式
    cout<<"旋转向量转化为旋转矩阵方法1：rotation matrix=\n"<<
        rotation_vector.toRotationMatrix()<<endl;
    cout<<"旋转向量转化为旋转矩阵方法2：rotation matrix=\n"<<
        rotation_vector.matrix();
    quat = rotation_vector;
    cout<<"旋转向量转化为四元数：quaternion=\n"<<quat.coeffs()<<endl;

    // 旋转矩阵转换为其他形式
    cout<<"旋转矩阵转换为旋转向量：rotation_vector axis=\n"<<
    rotation_vector.fromRotationMatrix(rotation_matrix).axis()<<
    "\n rotation_vector angle = "<<rotation_vector.fromRotationMatrix(rotation_matrix).angle()<<endl;
    // fromRotationMatrix 参数只适用于旋转向量，不适用于四元数

    rotation_vector = rotation_matrix;
    cout<<"旋转矩阵直接给旋转向量赋值初始化： rotation_vector angle= \n"<<rotation_vector.angle()<<endl;
    cout<<"rotation_vector axis=\n"<<rotation_vector.axis()<<endl;

    euler_angles = rotation_matrix.eulerAngles(2,1,0); //难点
    cout<<"旋转矩阵转化为欧拉角： yaw pitch roll="<<euler_angles.transpose()<<endl;
    quat = rotation_matrix;
    cout<<"旋转矩阵转化为四元数：quaternion=\n"<<quat.coeffs()<<endl;

    // 四元数转换为其他形式
    rotation_vector = quat;
    cout<<"四元数转化为旋转向量：rotation_vector axis=\n"<<rotation_vector.axis()
        <<"rotation_vector angle=\n"<<rotation_vector.angle()<<endl;
    
    rotation_matrix = quat.toRotationMatrix();
    cout<<"四元数转换为旋转矩阵方法1：rotation matrix=\n"<<rotation_matrix<<endl;

    rotation_matrix = quat.matrix();
    cout<<"四元数转化为旋转矩阵方法2：rotation matrix=\n"<<rotation_matrix<<endl;

    // 欧式变换矩阵

    // 欧式变换矩阵使用Eigen::Isometry ,仿射变换用Eigen::Affine3d, 射影变换用Eigen::Projective3d
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity();    // 初始化
    T.rotate(rotation_vector);
    Eigen::Vector3d v1 = Eigen::Vector3d(1,2,3);
    T.pretranslate(v1);

    cout<<"Transform matrix = \n"<<T.matrix()<<endl;
    cout<<"rotation matrix of T is :\n"<<T.rotation()<<endl;
    cout<<"translation of T is :\n"<<T.translation()<<endl;


    return 0;
}