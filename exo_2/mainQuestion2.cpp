#include "./mainQuestion2.hpp"

void mainQuestion2()
{
    // Getting the input values
    std::vector<int> inputVector;
    int sizeOfVector = getVectorFromInput("INP_MONO_SEQ.txt", inputVector);

    // Display the retrieved vector.
    std::cout << "The input vector is: " << std::endl;
    for (int value : inputVector)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Vectors that contains all 'greatest' vector of the moment.
    std::vector<std::vector<int>> greatestsVectors;

    // Iterating among all integers of the inputVector
    for (int integerToAdd : inputVector)
    {
        // Adding the integer to vectors.
        greatestsVectors = addIntegerIntoVectors(greatestsVectors, integerToAdd);
    }

    // Retrieve the greatest vector
    std::vector<int> greatestVector = getLongestSequence(greatestsVectors);

    // Display the longest vector.
    std::cout << "the longest vector is: " << std::endl;
    for (int value : greatestVector)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Writing the output into a text file
    writeVectorIntotextFile(greatestVector, "OUT_MONO_SEQ.txt");




    /*
    std::vector<std::vector<int>> vectors = {{1, 2, 3}, {4, 5, 6, 7}, {1, 1, 1, 1}} ;
    std::vector<int> greatestVector = getLongestSequence(vectors);
    // Display the longest vector.
    std::cout << "the longest vector is: " << std::endl;
    for (int value : greatestVector)
    {
        std::cout << value << " ";
    }
    */
}