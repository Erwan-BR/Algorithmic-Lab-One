#ifndef exo6_hpp
#define exo6_hpp

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <set>
#include <algorithm>

using namespace std;

vector<int> matrixCompute(vector<int> input);

std::vector<int> getVectorFromInput_Exo6(std::string intputFileName);

void writeVectorIntotextFile_Exo6(std::vector<int>, std::string outputFileName);

#endif /* exo6_hpp */
