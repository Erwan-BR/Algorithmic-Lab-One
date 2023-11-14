#ifndef exo3_hpp
#define exo3_hpp

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>

std::vector<std::vector<int>> getMatrixOfRests(const std::vector<int> inputVector, int divider);

std::vector<int> findLongestSequenceFromMatrix(const std::vector<int> originalVector, const std::vector<std::vector<int>> inputMatrix, int divider);

std::vector<int> getDataFromInput_Exo3(const std::string intputFileName, std::vector<int> &outputVector);
void writeDataIntotextFile_Exo3(const std::vector<int> indexOfVectorToWrite, const std::string outputFileName);

#endif /* exo3_hpp */