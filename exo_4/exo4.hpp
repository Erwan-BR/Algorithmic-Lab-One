#ifndef exo4_hpp
#define exo4_hpp

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void matrixProcess(vector<vector<int>> matrix, vector<vector<int>>* tree, vector<int>* processed, int node);
vector<int> matrixCompute(vector<int> input);

void listProcess(vector<vector<int>> matrix, vector<vector<int>>* tree, vector<int>* processed, int node);
vector<int> listCompute(vector<int> input);

std::vector<int> getVectorFromInput_Exo4(std::string intputFileName);
void writeVectorIntotextFile_Exo4(std::vector<int>, std::string outputFileName);

#endif /* exo4_hpp */