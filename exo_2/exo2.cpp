#include "./exo2.hpp"

std::vector<std::vector<int>> addIntegerIntoVectors(std::vector<std::vector<int>> vectorOfVectors, int integer)
{
    // If the integer is smaller than every last value in the vector of vectors, we have to create a vector that contains lony this value
    bool isPlacedInAVector = false;

    // New vector that may be add at the end of the loop
    std::vector<std::vector<int>> vectorsToAdd;

    // Looping among all vectors in the vector.
    for(std::vector<int> &nestedVector : vectorOfVectors)
    {
        // Display the nested vector.
        std::cout << "the nested vector is: " << std::endl;
        for (int value : nestedVector)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
        // If the integer is greater than the last value of this vector, we have two things to do :
        // 1. Keep the old vector if the gap is not one (because we could miss something by always keeping the integer)
        // 2. Create a new vector that contains the old one and the new value.
        
        // Checking if this integer is just after the last one.
        if (integer == nestedVector[nestedVector.size() - 1] + 1)
        {
            nestedVector.push_back(integer);
            isPlacedInAVector = true;
        }

        // Checking if this integer is bigger (2 or more) than the last one
        else if (integer > nestedVector[nestedVector.size() - 1])
        {
            // Copying the vector to keep a "save"
            std::vector<int> nestedVectorCopy = nestedVector;

            // Adding this vector to the vector that contains all of them
            vectorsToAdd.push_back(nestedVectorCopy);

            // Adding the integer to the nestedVector
            nestedVector.push_back(integer);
            isPlacedInAVector = true;
        }

        // If the integer is smaller : nothing to do
        else
        {
            continue;
        }
    }

    // If the value has been placed, we have to create an empty vector with just this value.
    // Will happen when the value is smallest never seen.
    if (!isPlacedInAVector)
    {
        std::vector<int> newVector = {integer};
        vectorOfVectors.push_back(newVector);
    }

    // Adding the vectors at the end of the current one.
    vectorOfVectors.insert(vectorOfVectors.end(), vectorsToAdd.begin(), vectorsToAdd.end());
    
    // At the end of adding this number to the saved vectors, we can delete the useless one.
    // Example : [1, 2, 7] ; [1, 7] --- No need to keep this one.

    // vectorOfVectors = cleanVectorFromUselessVectors_V2(vectorOfVectors, integer);

    std::cout << "----------------" << std::endl;

    return vectorOfVectors;
}

std::vector<std::vector<int>> cleanVectorFromUselessVectors(std::vector<std::vector<int>> vectorOfVectors, int integer)
{
    // Index that will help to know which vectors that end with integer is the longest.
    int indexOfGreatestThatEndByInteger = -1;

    // Size of the greatest vector that end by this integer
    int sizeOfGreatestThatEndByInteger = -1;

    // Index that count the position of the nested vector
    int index = 0;

    // Looping among all vectors in the vector.
    for (std::vector<int> nestedVector : vectorOfVectors)
    {
        if (integer == nestedVector[nestedVector.size() - 1] && nestedVector.size() > sizeOfGreatestThatEndByInteger)
        {
            // Update the sze of the biggest know vector
            sizeOfGreatestThatEndByInteger = nestedVector.size();

            // Delete the old vector with the useless index
            if (indexOfGreatestThatEndByInteger != -1)
            {
                vectorOfVectors.erase(vectorOfVectors.begin() + indexOfGreatestThatEndByInteger);
            }

            // Update the index of the biggest vector finishing by this value.
            indexOfGreatestThatEndByInteger = index;
        }

        // Updating the index of the position into vectorOfVectors.
        index++;
    }

    return vectorOfVectors;
}

std::vector<std::vector<int>> cleanVectorFromUselessVectors_V2(std::vector<std::vector<int>> vectorOfVectors, int integer)
{
    // Vectors that contains indexs to delete.
    std::vector<int> indexToDelete;

    // Current index
    int index = 0;

    // Size of the vector that contains the greatest number of value and ending by integer.
    int sizeOfGreatestThatEndByInteger = 0;

    // Index of the vector that contains the greatest number of value and ending by integer.
    int indexOfGreatestThatEndByInteger = -1;

    // Looping among all vectors in the vector.
    for (std::vector<int> &nestedVector : vectorOfVectors)
    {
        if (integer == nestedVector[nestedVector.size() - 1] && nestedVector.size() > sizeOfGreatestThatEndByInteger)
        {
            // Update the sze of the biggest know vector
            sizeOfGreatestThatEndByInteger = nestedVector.size();
            
            // If it's the first time a vector end by integer, we update the index and don't delete anything.
            if (-1 != indexOfGreatestThatEndByInteger)
            {
                // The previous biggest has to be deleted.
                indexToDelete.push_back(indexOfGreatestThatEndByInteger);
            }
            // Update the index of the biggest one
            indexOfGreatestThatEndByInteger = index;
        }

        // Updating the index of the position into vectorOfVectors.
        index++;
    }

    // Reverse the list of index to avoid modifying them
    std::reverse(indexToDelete.begin(), indexToDelete.end());

    // Deleting useless vectors 
    for (int deletingIndex : indexToDelete)
    {
        vectorOfVectors.erase(vectorOfVectors.begin() + deletingIndex);
    }
    return vectorOfVectors;
}

std::vector<int> getLongestSequence(std::vector<std::vector<int>> vectorOfVectors)
{
    // Creating an output vector
    std::vector<int> outputVector ;

    // If the vector is empty, return -1
    if (0 == vectorOfVectors.size())
    {
        return outputVector;
    }

    // Initialisation of the outputVector
    outputVector = vectorOfVectors[0];

    // Looping among all vectors in the vector.
    for (std::vector<int> &nestedVector : vectorOfVectors)
    {
        // If this vector is bigger, save it into the output value.
        if (nestedVector.size() > outputVector.size())
        {
            outputVector = nestedVector;
        }
    }

    return outputVector;
}

int getVectorFromInput(std::string intputFileName, std::vector<int> &outputVector)
{
    // Instanciation of the returned value.
    int returnedValue = -1;
    
    // Instantiation of a fstream object which is a file.
	std::fstream readingFile;

    // Choose an input folder name and concatenate it to the name of the file.
    std::string inputFolderName = "textFiles/";
    std::string intputFileToRead = inputFolderName + intputFileName;

	// Opening the file in reading mode.
	readingFile.open(intputFileToRead, std::ios::in);

	// Checking if the file is correctly opened.
	if (readingFile.is_open())
	{
        // Instantiation of a string that will represent the line in the document.
        std::string lineFromInputText;

        // Let's assume that the file is writen correctly : only two lines :
        // 1 : contains n.
        // 2 : contains the list, separated by spaces

        getline(readingFile, lineFromInputText);

        // Retrieve n.
        returnedValue = std::stoi(lineFromInputText);

        // Retrieve the second line into lineFromInputText to have a vector.
        std::getline(readingFile, lineFromInputText);

        // Create the string that contains tokens from the original string
        std::string token;

        // constructing stream from the string
        std::stringstream ss(lineFromInputText);

        // Looping while i can get another int
        while (getline(ss, token, ' '))
        {
            // Store token string in the vector
            outputVector.push_back(std::stoi(token));
        }

        // Closing the file because we do not need it anymore.
        readingFile.close();
    }
    return returnedValue;
}

void writeVectorIntotextFile(std::vector<int> vectorToWrite, std::string outputFileName)
{
    // Instantiation of a fstream object which is a file.
	std::fstream writingFile;

    // Choose an input folder name and concatenate it to the name of the file.
    std::string inputFolderName = "textFiles/";
    std::string intputFileToRead = inputFolderName + outputFileName;

	// Opening the file in reading mode.
	writingFile.open(intputFileToRead, std::ios::out);

	// Checking if the file is correctly opened.
	if (writingFile.is_open())
	{
		// Iterating among all students.
		for (int value : vectorToWrite)
		{
			// Writing in the terminal the textFile information concerning the current student.
			writingFile << value << " ";
		}
		// Closing the file because we do not need it anymore.
		writingFile.close();
	}
}