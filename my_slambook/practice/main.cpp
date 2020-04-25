#include <iostream>
#include<Eigen/Core>
#include<Eigen/Dense>

using namespace std;

int main(int, char**) {
    Eigen::Matrix<double,9,9> matrix_99 = Eigen::MatrixXd::Random(9,9);//MatrixXd是动态数组
    cout<<"big matrix is :\n"<<matrix_99<<endl;
    Eigen::Matrix3d matrix_33;
    for (int i = 0; i < 3; i++)
    {
        for (int j =0 ; j < 3; j++)
        {
            matrix_33(i,j) = matrix_99(i,j);
        }
        
    }
    cout<<"small matrix is:\n"<<matrix_33<<endl;
    return 0;
}
