#ifndef INC_FEMCASE_HPP
#define INC_FEMCASE_HPP

#include <Eigen/Dense>
#include <vector>
#include "super_elements.hpp"

/* MATRIX types
    These are the matrix types used for the different parts of the model. 
    The number of rows depends on the problems but columns are fixed.
*/
typedef Eigen::Matrix<double, Eigen::Dynamic, 3, Eigen::RowMajor> NODEmat;
typedef Eigen::Matrix<double, Eigen::Dynamic, 5, Eigen::RowMajor> CONNmat;
typedef Eigen::Matrix<double, Eigen::Dynamic, 3, Eigen::RowMajor> BCmat;
typedef Eigen::Matrix<double, Eigen::Dynamic, 6, Eigen::RowMajor> DOFSmat;

typedef Eigen::Matrix<double, Eigen::Dynamic, 3, Eigen::RowMajor> BCauxmat;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> Ktotalmat;


class FEMcase {
private:
    // Private vars
    NODEmat NODES;
    CONNmat CONN;
    BCmat BCs;
    DOFSmat DOFS;
    std::vector<SuperElement> ELs;
    Ktotalmat Kt;

    // Some helper functions
    BCmat expandBCs(const BCauxmat& in);
    DOFSmat generateDOFS(const NODEmat& in);

public:
    FEMcase(NODEmat nod, CONNmat con, BCauxmat bc);
    ~FEMcase() = default;

    Ktotalmat Assembler(void);

};


#endif