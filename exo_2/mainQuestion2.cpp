#include "./mainQuestion2.hpp"

void mainQuestion2()
{
    // Getting the input values
    std::vector<int> inputVector = getDataFromTextFile_Exo2("INP_MONO_SEQ.txt");

    // Display the retrieved vector.
    std::cout << "The input vector is: " << std::endl;
    for (int value : inputVector)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::vector<int> outputIndexForLongest = getLongestIncreasingSequenceIndexes(inputVector);

    // Display the indexes vector.
    std::cout << "The indexes of the longest subsequence of the input Vector are: " << std::endl;
    for (int index : outputIndexForLongest)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    std::vector<int> outputVector = getSequenceFromIndex(inputVector, outputIndexForLongest);

    // Display the longest subsequence
    std::cout << "The longest subsequence is: " << std::endl;
    for (int output : outputIndexForLongest)
    {
        std::cout << inputVector[output] << " ";
    }
    std::cout << std::endl;
    
    writeDataIntoTextFile_Exo2(outputVector, outputIndexForLongest, "OUT_MONO_SEQ.TXT");

    std::cout << "The output file, based on the input file, has been generated!" << std::endl;
}