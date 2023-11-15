#include "./mainQuestion3.hpp"

void mainQuestion3()
{
    std::vector<int> inputVector;

    // Returned value contains : 0 : Size of the vector, 2 : the divider.
    std::vector<int> returnedValues = getDataFromTextFile_Exo3("INP_DIV_SEQ.txt", inputVector);

    // Get the matrix of rests
    std::vector<std::vector<int>> generatedMatrix = getMatrixOfRests(inputVector, returnedValues[1]);

    // Retrieve the longest subsequence that can be divided by the desired divider.
    std::vector<std::vector<int>> outputVector = findLongestSequenceFromMatrix(inputVector, generatedMatrix, returnedValues[1]);

    // Display some informations in the terminal
    std::cout << "The original vector is:" << std::endl;
    for (int inputValue: inputVector)
    {
        std::cout << inputValue << " ";
    }
    std::cout << std::endl;

    int totalSum = 0;

    // Display the longest subsequence that can be divided by the desired divider
    std::cout << "The longest subsequence that can be divided by " << returnedValues[1] << " is:" << std::endl;
    for (std::vector<int> elementOfSubsequence : outputVector)
    {
        std::cout << elementOfSubsequence[0] << " ";
        totalSum += elementOfSubsequence[0];
    }
    std::cout << std::endl;

    // Display the sum
    std::cout << "The sum of this subsequence is: " << totalSum << std::endl;

    // Display the quantity of elements
    std::cout << "There is " << outputVector.size() << " elements in this subsequence." << std::endl;

    // Writing the result into an output file
    writeDataIntoTextFile_Exo3(outputVector, "OUT_DIV_SEQ.txt");

    std::cout << "The output file, based on the input file, has been generated!" << std::endl;
}