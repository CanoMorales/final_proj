//
// Created by Edniel Campos on 12/1/22.
//
#include <iostream>
#include "cgol.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void fillMatrix(std::vector<std::vector<int> > &matrix, int d);
void ReadFile(std::string file_name, std::vector<std::vector<int> > * vector);
bool is_empty(std::string file_name);
void WriteFile(std::string file_name, std::vector<std::vector<int> > &vector);

int main(int argc, char *argv[]){
    int dimensions = std::stoi(argv[1]);
    std::string matrix_input = "matrix_input.txt";
    std::string matrix_output = "matrix_output.txt";
    std::vector<std::vector<int> > matrix;
    fillMatrix(matrix, dimensions);
    WriteFile(matrix_output, matrix);
//    if (is_empty(matrix_input) == true){
//        fillMatrix(matrix, dimensions);
//        WriteFile(matrix_input, matrix);
//    } else {
//        ReadFile(matrix_output, &matrix);
//        WriteFile(matrix_input, matrix);
//    }
    CGOL object(matrix, dimensions);
    object.timeTicks();
    object.printMatrix();
    //WriteFile(matrix_output, object.Matrix);
    return 0;
}
bool is_empty(std::string file_name){
    std::ifstream file(file_name);
    return file.peek() == std::ifstream::traits_type::eof();
}
void fillMatrix(std::vector<std::vector<int> > &matrix, int d){
    std::vector<int> temp;
    for(int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            temp.push_back((rand() % 100) < 25);
        }
        matrix.push_back(temp);
        temp.clear();
    }
}
void ReadFile(std::string file_name, std::vector<std::vector<int> > * vector){
    std::ifstream file(file_name);
    std::string str;
    while (std::getline(file, str)) {
        std::vector<int> new_row;
        std::istringstream ss(str);
        double token;
        while(ss >> token){
            new_row.push_back(token);
        }
        vector->push_back(new_row);
    }
}
void WriteFile(std::string file_name, std::vector<std::vector<int> > &vector){
    std::ofstream output_file(file_name);
    for(std::vector<std::vector<int> >::const_iterator i = (vector).begin(); i != (vector).end(); ++i){
        for(std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j){
            output_file << *j << " ";
        }
        output_file << "\n";
    }
}