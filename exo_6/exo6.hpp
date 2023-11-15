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

vector<int> matrixCompute_Exo6(vector<int> input);

vector<int> getDataFromTextFile_Exo6(string intputFileName);
void writeDataIntoTextFile_Exo6(vector<int>, string outputFileName);

#endif /* exo6_hpp */
