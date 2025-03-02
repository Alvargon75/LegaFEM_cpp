#ifndef INC_ELEM_1D_HPP
#define INC_ELEM_1D_HPP

#include "super_elements.hpp"
#include <iostream>

// Bar element
class Elem1DBar: public SuperElement1D 
{
private:
    /* data */
public:
    Elem1DBar(Eigen::Matrix<double, 2, 3> nodes_, PROP1D proper);
    ~Elem1DBar() = default;

    void buildStiffnessMatrix() override;
};


#endif