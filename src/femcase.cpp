#include "femcase.hpp"

FEMcase::FEMcase(NODEmat nod, CONNmat con, BCauxmat bc){
    NODES = nod;
    CONN = con;

    BCs = expandBCs(bc);

    DOFS = generateDOFS(NODES);

}


BCmat FEMcase::expandBCs(const BCauxmat& in){
    std::vector<Eigen::VectorXd> newBCs;

    for(int j = 0; j < in.rows(); j++){
        if(in(j,2) <= 6){
            newBCs.push_back(in.row(j));
        } else {
            int value = static_cast<int>(in(j,2));
            std::vector<int> digits;
            while(value > 0){
                digits.push_back(value % 10);
                value /= 10;
            }
            std::reverse(digits.begin(), digits.end());

            for(int digit : digits){
                Eigen::VectorXd newRow(3);
                newRow << in(j, 0), in(j, 1), digit;
                newBCs.push_back(newRow);
            }
        }
    }

    Eigen::MatrixXd result(newBCs.size(), 3);
    for(size_t i = 0; i < newBCs.size(); i++){
        result.row(i) = newBCs[i];
    }

    return result;
}


DOFSmat FEMcase::generateDOFS(const NODEmat& in){
    int n = in.rows();
    Eigen::VectorXd vec = Eigen::VectorXd::LinSpaced(n*6, 1, n*6);
    DOFSmat DOFS = Eigen::Map<Eigen::MatrixXd>(vec.data(), 6,n).transpose();

    return DOFS;
}

Ktotalmat FEMcase::Assembler(void){
    
}
