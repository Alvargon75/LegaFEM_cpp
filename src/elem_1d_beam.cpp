#include "elem_1d.hpp"

#include <cmath>
#include <iostream>


Elem1DBeam::Elem1DBeam(Eigen::Matrix<double, 2, 3> nodes_, PROP1D proper){
    Eigen::Vector3d tempL;

    nodes = nodes_;
    property = proper;

    // get length
    tempL = nodes.row(0) - nodes.row(1);
    L = tempL.norm();


    buildRotationMatrix();
    buildStiffnessMatrix();
}

void Elem1DBeam::buildStiffnessMatrix(){
    PROP1D p = property;
    double G = p.E/(2 * (1 + p.nu));

    K << p.A*p.E/L, 0, 0, 0, 0, 0, -p.A*p.E/L, 0, 0, 0, 0, 0,
    0, 12.*p.E*p.Izz/pow(L,3), 0, 0, 0, 6.*p.E*p.Izz/pow(L,2), 0, -12.*p.E*p.Izz/pow(L,3), 0, 0, 0, 6.*p.E*p.Izz/pow(L,2),
    0, 0, 12.*p.E*p.Iyy/pow(L,3), 0, -6.*p.E*p.Iyy/pow(L,2), 0, 0, 0, -12.*p.E*p.Iyy/pow(L,3), 0, -6.*p.E*p.Iyy/pow(L,2), 0,
    0, 0, 0, G*p.J/L, 0, 0, 0, 0, 0, -G*p.J/L, 0, 0,
    0, 0, -6*p.E*p.Iyy/pow(L,2), 0, 4*p.E*p.Iyy/L, 0, 0, 0, 6*p.E*p.Iyy/pow(L,2), 0, 2*p.E*p.Iyy/L, 0,
    0, 6*p.E*p.Izz/pow(L,2), 0, 0, 0, 4*p.E*p.Izz/L, 0, -6*p.E*p.Izz/pow(L,2), 0, 0, 0, 2*p.E*p.Izz/L,
    -p.A*p.E/L, 0, 0, 0, 0, 0, p.A*p.E/L, 0, 0, 0, 0, 0,
    0, -12*p.E*p.Izz/pow(L,3), 0, 0, 0, -6*p.E*p.Izz/pow(L,2), 0, 12*p.E*p.Izz/pow(L,3), 0, 0, 0, -6*p.E*p.Izz/pow(L,2),
    0, 0, -12*p.E*p.Iyy/pow(L,3), 0, 6*p.E*p.Iyy/pow(L,2), 0, 0, 0, 12*p.E*p.Iyy/pow(L,3), 0, 6*p.E*p.Iyy/pow(L,2), 0,
    0, 0, 0, -G*p.J/L, 0, 0, 0, 0, 0, G*p.J/L, 0, 0,
    0, 0, -6*p.E*p.Iyy/pow(L,2), 0, 2*p.E*p.Iyy/L, 0, 0, 0, 6*p.E*p.Iyy/pow(L,2), 0, 4*p.E*p.Iyy/L, 0,
    0, 6*p.E*p.Izz/pow(L,2), 0, 0, 0, 2*p.E*p.Izz/L, 0, -6*p.E*p.Izz/pow(L,2), 0, 0, 0, 4*p.E*p.Izz/L;
}

