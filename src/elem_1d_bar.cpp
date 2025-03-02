#include "elem_1d.hpp"
#include <iostream>

Elem1DBar::Elem1DBar(Eigen::Matrix<double, 2, 3> nodes_, PROP1D proper){
    Eigen::Vector3d tempL;

    nodes = nodes_;
    property = proper;

    // get length
    tempL = nodes.row(0) - nodes.row(1);
    L = tempL.norm();


    buildRotationMatrix();
    buildStiffnessMatrix();
}


void Elem1DBar::buildStiffnessMatrix(){
    double mult;

    mult = property.E * property.A / L;

    K << 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;

    K *= mult;

}
