#include<iostream>
#include<ctime>
using namespace  std;

//Eigen 部分
#include<Eigen/Core>
// 稠密矩阵的代数运算（逆 特征值）
#include<Eigen/Dense>

#define MATRIX_SIZE 50

int main (int argc, char** argv)
{
    Eigen::Matrix <float, 2, 3> matrix_23; 
    Eigen::Vector3d v_3d;
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();//初始化为0
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;//动态数组

    Eigen::MatrixXd matrix_x;

    //赋值
    matrix_23<<1,2,3,4,5,6;
    //输出
    cout<<matrix_23<<endl;
    //访问矩阵元素
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<matrix_23(i,j)<<endl;
        }
    }
    v_3d<<3,2,1;
    Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>()*v_3d;//显示转换
    cout<<result<<endl;

    matrix_33 = Eigen::Matrix3d::Random();
    cout<<matrix_33<<endl<<endl;

    cout<<matrix_33.transpose()<<endl;//转秩
    cout<<matrix_33.sum()<<endl;//个元素和
    cout<<matrix_33.trace()<<endl;//迹
    cout<<10*matrix_33<<endl;//数乘
    cout<<matrix_33.inverse()<<endl;//逆
    cout<<matrix_33.determinant()<<endl;//行列式

    //特征值
    //实对称矩阵可以保证对角化成功
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver (matrix_33.transpose()*matrix_33);
    cout<<"Eigen values ="<<eigen_solver.eigenvalues()<<endl;
    cout<<"Eigen vectors ="<<eigen_solver.eigenvectors()<<endl;

    //解方程 AX=B
    Eigen::Matrix<double,MATRIX_SIZE,MATRIX_SIZE> matrix_NN;
    matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE,MATRIX_SIZE);
    Eigen::Matrix<double,MATRIX_SIZE,1> v_nd = Eigen::MatrixXd::Random(MATRIX_SIZE,1);//上面的两句也可以合成一句

    clock_t time_stt =clock();//计时
    //直接求逆
    Eigen::Matrix<double,MATRIX_SIZE,1> x = matrix_NN.inverse()*v_nd;
    cout<<"time use in normal inverse is"<<1000*(clock() - time_stt)/(double)CLOCKS_PER_SEC<<"ns"<<endl;

    //通常使用矩阵分解来求，比如QR分解，速度会快很多
    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_nd);
    cout<<"time use in Qr composition is"<<1000*(clock() - time_stt)/(double)CLOCKS_PER_SEC<<"ns"<<endl;


    return 0;
}
