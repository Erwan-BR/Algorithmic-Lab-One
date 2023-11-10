#include "./main.hpp"

int main()
{
    // Table of pointers to the different functions.
    void (*functions[])(void) = {nullptr, mainQuestion1, mainQuestion2, mainQuestion3, mainQuestion4, mainQuestion5, mainQuestion6};
    int userInput = -1;
    do
    {
        try
        {
            // Showing a prompt to the user
            std::cout << std::endl << "Type any number from 1 to 6 to see what the associated exercice main function does. ";
            std::cout << "Type 0 to exit." << std::endl;
            
            // Asking the number of the question he wanna see the answer.
            std::cin >> userInput;
            
            // Handle error (too large integers, string)
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number." << std::endl;
            }
            // Quit the program if the user wants to
            else if (userInput == 0)
            {
                return 0;
            }
            // Call the function associated to the number.
            else if (userInput > 0 && userInput <= 6)
            {
                functions[userInput]();
            }
            // In case the user try to type 7 or whatever which is not a question in our table.
            else
            {
                std::cout << "Invalid choice." << std::endl;
            }
        }

        // Catching potential errors
        catch(const std::exception& e)
        {
            std::cerr << "Invalid input. Please enter a number between 1 and 6." << std::endl;
        }
        // Re-initialize userInput
        userInput = -1;
    } while (true);

    return 0;
}
