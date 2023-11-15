#ifndef exo4_hpp
#define exo4_hpp

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void matrixProcess_Exo4(const vector<vector<int>> matrix, vector<vector<int>>* tree, vector<int>* processed, int inputNode);
vector<int> matrixCompute_Exo4(vector<int> input);

void listProcess_Exo4(vector<vector<int>> matrix, vector<vector<int>>* tree, vector<int>* processed, int inputNode);
vector<int> listCompute_Exo4(vector<int> input);

vector<int> getDataFromTextFile_Exo4(string intputFileName);
void writeDataIntoTextFile_Exo4(vector<int>, string outputFileName);

#endif /* exo4_hpp */