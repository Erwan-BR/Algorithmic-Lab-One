#include "./mainQuestion3.hpp"

void mainQuestion3()
{
    std::vector<int> inputVector;
    std::vector<int> returnedValues = getDataFromTextFile_Exo3("INP_DIV_SEQ.txt", inputVector);

    // Display Information concerning the input
    std::cout << "We keep only " << returnedValues[0] << " values from the vector." << std::endl;
    std::cout << "We are looking for longest subsequence that can be divided by " << returnedValues[1] << "." << std::endl;

    // Display the input vector
    std::cout << "The input Vector is: " ;
    for (int index : inputVector)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Get the matrix
    std::vector<std::vector<int>> generatedMatrix = getMatrixOfRests(inputVector, returnedValues[1]);

    // Display the matrix
    std::cout << "The matrix is: " << std::endl ;
    for (std::vector<int> lineOfMatrix : generatedMatrix)
    {
        for (int valueInMatrix : lineOfMatrix)
        {
            std::cout << valueInMatrix << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Retrieve the longest subsequence that can be divided by the desired divider.
    std::vector<std::vector<int>> outputVector = findLongestSequenceFromMatrix(inputVector, generatedMatrix, returnedValues[1]);

    int totalSum = 0;

    // Display the longest subsequence that can be divided by the desired divider
    std::cout << "The output Vector is: " << std::endl;
    for (std::vector<int> elementOfSubsequence : outputVector)
    {
        std::cout << elementOfSubsequence[0] << " ";
        totalSum += elementOfSubsequence[0];
    }
    std::cout << std::endl;

    // Display the sum
    std::cout << "The sum of this sequence is: " << totalSum << std::endl;

    // Display the quantity of elements
    std::cout << "There is " << outputVector.size() << " elements in this subsequence." << std::endl;

    // Writing the result into an output file
    writeDataIntoTextFile_Exo3(outputVector, "OUT_DIV_SEQ.txt");
    std::cout << "The output file has been created." << std::endl;
}