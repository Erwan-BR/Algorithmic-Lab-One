#ifndef exo2_hpp
#define exo2_hpp

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>

std::vector<std::vector<int>> addIntegerIntoVectors(std::vector<std::vector<int>> vectorOfVectors, int integer);
std::vector<std::vector<int>> cleanVectorFromUselessVectors(std::vector<std::vector<int>> vectorOfVectors, int integer);
std::vector<std::vector<int>> cleanVectorFromUselessVectors_V2(std::vector<std::vector<int>> vectorOfVectors, int integer);
std::vector<int> getLongestSequence(std::vector<std::vector<int>> vectorOfVectors);

int getVectorFromInput(std::string intputFileName, std::vector<int> &outputVector);
void writeVectorIntotextFile(std::vector<int> vectorToWrite, std::string outputFileName);

#endif /* exo2_hpp */