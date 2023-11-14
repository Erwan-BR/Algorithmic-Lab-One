#include "./mainQuestion3.hpp"

void mainQuestion3()
{
    /*std::vector<int> outputVector;
    std::vector<int> returnedValues = getDataFromInput_Exo3("INP_DIV_SEQ", outputVector);

    // Display Information concerning the input
    std::cout << "We keep only " << returnedValues[0] << " values from the vector." << std::endl;
    std::cout << "We are looking for longest susbsequence that can be divided by" << returnedValues[1] << "." << std::endl;

    // Display the input vector
    std::cout << "The input Vector is: " ;
    for (int index : outputVector)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;*/

    // std::vector<int> inVect = {5, 3, 2, 1, 1, 6};
    std::vector<int> inVect = {1, 6, 11, 5, 10, 15, 20, 2, 4, 9};

    // Display the input vector
    std::cout << "The input Vector is: " ;
    for (int index : inVect)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> myMatrix = getMatrixOfRests(inVect, 5);

    // Display the matrix
    std::cout << "The matrix is: " ;
    for (std::vector<int> index : myMatrix)
    {
        for (int value : index)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> outVect = findLongestSequenceFromMatrix(inVect, myMatrix, 5);

    // Display the output vector
    std::cout << "The output Vector is: " << std::endl;
    for (int index : outVect)
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Display the sum
    std::cout << "The sum of the output Vector is: " << accumulate(outVect.begin(), outVect.end(), 0)<< std::endl;

}