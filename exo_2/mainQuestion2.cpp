#include "./mainQuestion2.hpp"

void mainQuestion2()
{
    // Getting the input values
    std::vector<int> inputVector;
    int sizeOfVector = getDataFromInput("INP_MONO_SEQ.txt", inputVector);

    // Display the retrieved vector.
    std::cout << "The input vector is: " << std::endl;
    for (int value : inputVector)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::vector<int> outputIndexForLongest = getLongestIncreasingSequence(inputVector);

    // Display the indexes vector.
    std::cout << "The indexes of the longest subsequence of the input Vector are: " << std::endl;
    for (int index : outputIndexForLongest)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Display the longest subsequence
    std::cout << "The longest subsequence is: " << std::endl;
    for (int output : outputIndexForLongest)
    {
        std::cout << inputVector[output] << " ";
    }
    std::cout << std::endl;
}