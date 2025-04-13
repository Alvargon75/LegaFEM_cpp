#include <iostream>
#include <Eigen/Dense>

#include "femcase.hpp"
#include "super_elements.hpp"
#include "elem_1d.hpp"

PROP1D testprop = {
    .E = 1,
    .A = 1,
    .nu = 0,
    .J = 1,
    .Izz = 1,
    .Iyy = 1,
    .j_aux = {0, 1, 0},
    .b = 0.1,
    .h = 0.1
};

int main(){

    // first chill test

    Eigen::Matrix<double, 2, 3> pos;
    Eigen::Matrix<double, 1, 3> bc_test;
    Eigen::Matrix<double, 1, 5> conn_test;
    

    pos << 0, 0, 0,
           1, 0, 0;

    bc_test << 1, 0, 123;

    conn_test << 0, 1, 0, 0, 1;

    Elem1DBar elem1(pos, testprop);
    Elem1DBeam elem2(pos, testprop);

    std::cout << elem1.getK() << std::endl;
    std::cout << elem2.getK() << std::endl;



    FEMcase defcase(pos, conn_test, bc_test);

    return 0;
}

