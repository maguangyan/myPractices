#include<iostream>
#include<cmath>

using namespace std;

#include<Eigen/Core>
#include<Eigen/Geometry>

int main(int argc, char** argv)
{
    int k = 10;
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();//单位矩阵
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1));//旋转向量 沿z轴旋转45度
    cout.precision(3);
    cout<<rotation_matrix<<endl;
    cout<<"rotation vector="<<rotation_vector.matrix()<<endl;//将旋转向量转为矩阵
    //也可以直接赋值
    rotation_matrix = rotation_vector.toRotationMatrix();
    cout<<rotation_matrix<<endl;
    //用AngleAxis可以进行坐标变换
    Eigen::Vector3d v(1, 0 ,0);
    Eigen::Vector3d v_rotated=rotation_vector*v;
    cout<<"(1,0,0)after rotation:\n"<<v_rotated<<endl;
    //或者用旋转矩阵
    v_rotated = rotation_matrix*v;
    cout<<"(1,0,0) after rotation:\n"<<v_rotated.transpose()<<endl;
    //欧拉角
    Eigen::Vector3d euler_angle = rotation_matrix.eulerAngles(2,1,0);//z y x的顺序
    cout<<"yaw pitch roll=\n"<<euler_angle.transpose()<<endl;
    //欧式变换矩阵 使用Eigen::Isometry
    Eigen::Isometry3d T =Eigen::Isometry3d::Identity();//is 4 * 4
    T.rotate(rotation_vector);//按照rotation_vector 进行旋转
    T.pretranslate(Eigen::Vector3d(1,3,4));
    cout<<"Transform matrix=:\n"<<T.matrix()<<endl;
    //用变换矩阵进行坐标变换
    Eigen::Vector3d v_tranformed = T*v;
    cout<<"v tranformed is:\n"<<v_tranformed.transpose()<<endl;

    //对于仿射
    //四元数
    Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
    cout<<"quaternion =\n"<<q.coeffs()<<endl;
    q = Eigen::Quaterniond(rotation_matrix);
    cout<<"quaternion is \n"<<q.coeffs()<<endl;
    //使用四元数旋转一个向量
    v_rotated = q*v;
    cout<<"(1,0,0) after rotation is\n"<<v_rotated.transpose()<<endl;











    return 0;
}