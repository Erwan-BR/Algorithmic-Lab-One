#ifndef exo2_hpp
#define exo2_hpp

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>

std::vector<int> getLongestIncreasingSequence(const std::vector<int>& inputVector);

int getDataFromInput(const std::string intputFileName, std::vector<int> &outputVector);
void writeDataIntotextFile(const std::vector<int> indexOfVectorToWrite, const std::string outputFileName);

#endif /* exo2_hpp */