#ifndef exo2_hpp
#define exo2_hpp

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>

std::vector<int> getLongestIncreasingSequenceIndexes(const std::vector<int>& inputVector);
std::vector<int> getSequenceFromIndex(const std::vector<int> &vectorToRetrieve, const std::vector<int> &listOfIndexes);

std::vector<int> getDataFromTextFile_Exo2(const std::string intputFileName);
void writeDataIntoTextFile_Exo2(const std::vector<int> vectorToWrite, const std::vector<int> originalIndexes, const std::string outputFileName);

#endif /* exo2_hpp */