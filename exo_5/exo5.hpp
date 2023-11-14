#ifndef exo5_hpp
#define exo5_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void matrixProcess(vector<vector<int>> matrix, vector<int>* comp, vector<int>* processed, int node);
vector<vector<int>> matrixCompute(vector<int> input);

void listProcess(vector<vector<int>> matrix, vector<int>* comp, vector<int>* processed, int node);
vector<vector<int>> listCompute(vector<int> input);

std::vector<int> getVectorFromInput_Exo5(std::string intputFileName);
void writeVectorIntotextFile_Exo5(std::vector<std::vector<int>>, std::string outputFileName);

#endif /* exo5_hpp */