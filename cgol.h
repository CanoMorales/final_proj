//
// Created by Edniel Campos on 12/1/22.
//

#ifndef FINAL_PROJ_CGOL_H
#define FINAL_PROJ_CGOL_H

#include <vector>
#include <iostream>

class CGOL{
public:
    std::vector<std::vector<int> > Matrix;
    int Dimensions;
    CGOL(){};
    ~CGOL(){};
    CGOL(std::vector<std::vector<int> > &matrix, int dimensions);
    void timeTicks();
    int neighborAmount(std::vector<std::vector<int> > &matrix, int r, int c, int Dimensions);
    int aliveOrDead(int neighbors, int value);
    void printMatrix();
    void WriteFile();
};

#endif //FINAL_PROJ_CGOL_H
