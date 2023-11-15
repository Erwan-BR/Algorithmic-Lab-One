#ifndef exo5_hpp
#define exo5_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void matrixProcess_Exo5(vector<vector<int>> matrix, vector<int>* comp, vector<int>* processed, int inputNode);
vector<vector<int>> matrixCompute_Exo5(vector<int> input);

void listProcess_Exo5(vector<vector<int>> matrix, vector<int>* comp, vector<int>* processed, int node);
vector<vector<int>> listCompute_Exo5(vector<int> input);

vector<int> getDataFromTextFile_Exo5(string intputFileName);
void writeDataIntoTextFile_Exo5(vector<vector<int>>, string outputFileName);

#endif /* exo5_hpp */