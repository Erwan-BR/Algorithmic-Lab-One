#include "./mainQuestion1.hpp"

void mainQuestion1()
{
    try
    {
        std::string userInput;
        
        // Showing a prompt to the user
        std::cout << std::endl << "Type any positive integer you are targetting." << std::endl;
        
        // Asking the number of the question he want to see the answer.
        std::cin >> userInput;
        
        // Handle error (too large integers, string)
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input." << std::endl;
            return ;
        }

        // Convert the user input into an integer
        int userInputInteger = std::stoi(userInput);

        // Prevent the user to give a negative (or null) target.
        if (0 >= userInputInteger)
        {
            std::cout << "You must type a positive integer." << std::endl;
        }

        // Retrieve the seracuse sequence.
        std::vector<bool> syracuseSequence = getSequenceSyracuse(userInputInteger);

        // Display the sequence in a readable way.
        displayConstructionOfN(syracuseSequence, userInputInteger);
    }

    // Catching potential errors
    catch(const std::exception& e)
    {
        std::cerr << "Invalid input." << std::endl;
        return ;
    }
}