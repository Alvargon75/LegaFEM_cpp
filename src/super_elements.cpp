#include "super_elements.hpp"

// SUPER ELEMENT 1D GENERIC METHODS

void SuperElement1D::buildRotationMatrix(void){
    Eigen::Vector3d node1 = nodes.row(0);
    Eigen::Vector3d node2 = nodes.row(1);
    
    Eigen::Vector3d i_hat, j_hat, k_hat;  

    Eigen::Matrix<double, 3, 3> R_lil;


    i_hat = node2 - node1;
    i_hat = i_hat/i_hat.norm();

    if(property.j_aux.norm() <= 1e-6){std::cout << "ERROR: j_aux can't be parallel to bar" << std::endl;}

    k_hat = i_hat.cross(property.j_aux);
    k_hat = k_hat/k_hat.norm();

    j_hat = k_hat.cross(i_hat);

    R_lil << i_hat, j_hat, k_hat;

    // place into the real property

    R << R_lil, Eigen::Matrix3d::Zero(3,3), Eigen::Matrix3d::Zero(3,3), Eigen::Matrix3d::Zero(3,3),
         Eigen::Matrix3d::Zero(3,3), R_lil, Eigen::Matrix3d::Zero(3,3), Eigen::Matrix3d::Zero(3,3),
         Eigen::Matrix3d::Zero(3,3), Eigen::Matrix3d::Zero(3,3), R_lil, Eigen::Matrix3d::Zero(3,3),
         Eigen::Matrix3d::Zero(3,3), Eigen::Matrix3d::Zero(3,3), Eigen::Matrix3d::Zero(3,3), R_lil;

}

// SUPER ELEMENT 2D GENERIC METHODS
