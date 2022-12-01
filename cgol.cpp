//
// Created by Edniel Campos on 12/1/22.
//

#include "cgol.h"
#include <vector>
#include <iostream>
#include "cgol.h"

//f(&a) will automatically reference and dereference a and changes will take place outside of function
//f(a) will give a copy of a but not make changes outside
//f(*a) will give you a pointer and you will have to dereference it everytime it is used,
//only use this when your pointer has a chance of being NULL


CGOL::CGOL(std::vector<std::vector<int> > &matrix, int dimensions){
    Dimensions = dimensions;
    std::vector<int> temp;
    for (int i = 0; i < Dimensions; i++){
        for (int j = 0; j < Dimensions; j++){
            temp.push_back(matrix[i][j]);
        }
        Matrix.push_back(temp);
        temp.clear();
    }

}
void CGOL::timeTicks(){
    std::vector<std::vector<int> > matrixNext;
    std::vector<int> temp1;
    int neighbors;
    int pixelValue;
    for (int i = 0; i < Dimensions; i++){
        for (int j = 0; j < Dimensions; j++){
            neighbors = neighborAmount(Matrix, i, j, Dimensions);
            pixelValue = Matrix[i][j];
            temp1.push_back(aliveOrDead(neighbors, pixelValue));
        }
        matrixNext.push_back(temp1);
        temp1.clear();
    }
    for (int i = 0; i < Dimensions; i++){
        for (int j = 0; j < Dimensions; j++){
            Matrix[i][j] = matrixNext[i][j];
        }
    }
    return;
}
int CGOL::neighborAmount(std::vector<std::vector<int> > &matrix, int r, int c, int d){
    int amount = 0;
    if (r > 0){
        if ((matrix[r-1][c]) == 1)
            amount++;
    }
    if (r < d-1){
        if ((matrix[r+1][c]) == 1)
            amount++;
    }
    if (c > 0){
        if ((matrix[r][c-1]) == 1)
            amount++;
    }
    if (c < d-1){
        if ((matrix[r][c+1]) == 1)
            amount++;
    }
    if ((r > 0) && (c > 0)){
        if ((matrix[r-1][c-1]) == 1)
            amount++;
    }
    if ((r < d-1) && (c > 0)){
        if ((matrix[r+1][c-1]) == 1)
            amount++;
    }
    if ((r > 0) && (c < d-1)){
        if ((matrix[r-1][c+1]) == 1)
            amount++;
    }
    if ((r < d-1) && (c < d-1)){
        if ((matrix[r+1][c+1]) == 1)
            amount++;
    }
    return amount;
}
int CGOL::aliveOrDead(int neighbors, int value){
    if (value == 0){
        if (neighbors == 3){
            return 1;
        } else {
            return 0;
        }
    } else if (value == 1){
        if (neighbors < 2){
            return 0;
        } else if (neighbors > 3){
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}
void CGOL::printMatrix(){
    for (int i = 0; i < Dimensions; i++){
        for (int j = 0; j < Dimensions; j++){
            std::cout << Matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return;
}