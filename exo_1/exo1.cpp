#include "./exo1.hpp"

/// @brief Find the sequence of Syracuse to go from N to 1.
/// @param N Starting value
/// @return Vector of 0 / 1. 0 : divide by 2, 1 : multiply by 3.
std::vector<bool> getSequenceSyracuse(int N)
{
    // Instanciation of an empty vector
    std::vector<bool> outputVector ;

    if (1 >= N)
    {
        return {};
    }

    while (1 != N)
    {
        // Add 0 to the vector if N can be divided by 2, 1 else.
        //outputVector.push_back(0 == N % 2);
        // If N is even, we divide N by two and add true to the sequence.
        if (0 == (N % 2))
        {
            N /= 2;
            outputVector.push_back(true);
        }
        // if N is odd, we multiply N by 3 and we add to the sequence.
        else
        {
            N = (3 * N) + 1;
            outputVector.push_back(false);
        }
    }
    return outputVector;
}

/// @brief Display how to construct N when we start with one.
/// @param syracuseSequence Seracuse sequence of how to get 1 from N.
/// @param target The value that we want to construct at the end.
void displayConstructionOfN(const std::vector<bool> &syracuseSequence, int target)
{
    // Should not be called with a negative target.
    if (0 >= target)
    {
        return;
    }

    // Display the starting value
    std::cout << "1 " ;

    // Reading the sequence from end to beginning to have it in the right order.
    for (int index = syracuseSequence.size() - 1; 0 <= index; index--)
    {
        // If the value is 0, it means that the number was divided by 2 so we have to multiply it by 2.
        // If the value is 0, it means that the number was multiplied by 3 so we have to divide it by 3.
        if (syracuseSequence[index])
        {
            std::cout << "*2 ";
        }
        else
        {
            std::cout << "/3 ";
        }
    }

    // Display the egality with the target.
    std::cout << " = " << target << std::endl;
}