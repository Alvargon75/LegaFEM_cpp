#include <iostream>
#include <super_elements.hpp>
#include "elem_1d.hpp"
#include <Eigen/Dense>

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
    Eigen::Matrix<double, 2, 3> pos;

    pos << 0, 0, 0,
           1, 0, 0;

    Elem1DBar elem1(pos, testprop);

    elem1.printR();

    return 0;
}

