#ifndef INC_SUPER_ELEMENTS_HPP
#define INC_SUPER_ELEMENTS_HPP

#include <Eigen/Dense>
#include <iostream>


// Property for 1D elements
typedef struct {
    double E;
    double A;
    double nu;
    double J;
    double Izz;
    double Iyy;
    Eigen::Matrix<double, 3, 1> j_aux;
    double b;
    double h;
} PROP1D;

// Intflags
typedef enum {
    INTFLAG_2D_FULL = 0,
    INTFLAG_2D_REDUCEDSHEAR,
    INTFLAG_2D_REDUCEDAXIAL,
    INTFLAG_2D_REDUCED
} INTFLAGS_2D;

// Property for 2D elements
typedef struct {
    double E;
    double h;
    double nu;
} PROP2D;



// Abstract class implementation for 1D element
class SuperElement1D
{
protected:
    Eigen::Matrix<double, 12, 12> K;
    Eigen::Matrix<double, 12, 12> R;
    double L;
    Eigen::Matrix<double, 6, 2> u;
    Eigen::Matrix<double, 6, 2> DOFs;
    Eigen::Matrix<double, 2, 3> nodes;
    PROP1D property;

    // rotation matrix func, common for all 1d elems
    void buildRotationMatrix(void);
    virtual void buildStiffnessMatrix(void) = 0;

public:
    SuperElement1D() = default;
    virtual ~SuperElement1D() = default;

};



// Abstract class implementation for 2D element
class SuperElement2D
{
protected:
    Eigen::Matrix<double, 24, 24> K;
    Eigen::Matrix<double, 24, 24> R;
    Eigen::Matrix<double, 3, 3> R_small;
    Eigen::Matrix<double, 6, 4> DOFs;
    Eigen::Matrix<double, 4, 3> nodes;
    Eigen::Matrix<double, 6, 2> u;

public:
    SuperElement2D() = default;
    virtual ~SuperElement2D() = default;
};






#endif