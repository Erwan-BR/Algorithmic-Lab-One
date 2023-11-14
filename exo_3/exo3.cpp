#include "./exo3.hpp"

/// @brief Allows to get the matrix of rests, which is n * l (n = inputVector.size(), l = divider)
/// @param inputVector Vector where we are searching the longest subsequence that can be divided by divider.
/// @param divider Value that must divide the subsequence.
/// @return Matrix that contains the different rests.
std::vector<std::vector<int>> getMatrixOfRests(const std::vector<int> inputVector, int divider)
{
    // Checking if the input matrix is empty
    if (0 == inputVector.size())
    {
        return {{}};
    }

    // Construct an empty matrix.
    std::vector<std::vector<int>> outputMatrix(inputVector.size(), std::vector<int>(divider, 0));

    // Instanciation and initialization of a vector that contains the longest subsequence possible
    // for a given rest.
    std::vector<int> maxSizeByRest;
    for (int index = 0; index < divider; index++)
    {
        maxSizeByRest.push_back(0);
    }

    // Initialization of the table and adding the subsequence to the rest vectors
    outputMatrix[0][inputVector[0] % divider] = 1;
    maxSizeByRest[inputVector[0] % divider] = 1;

    // Iterating among all values from inputVector
    for (int index = 1; index < inputVector.size(); index++)
    {
        // Iterating among all possibles rests from the division
        for (int subIndex = 0; subIndex < divider; subIndex++)
        {
            bool valueFoundOnColumn = false;
            
            // Searching on the previous lines that can give the longest subsequence with this rest
            for (int subSubIndex = index - 1; 0 <= subSubIndex; subSubIndex--)
            {
                // If a value is stored, then i can take this old rest to add the new element and knowing a
                // new subsequence with a maximum length for a given rest.
                if (0 != outputMatrix[subSubIndex][subIndex])
                {
                    // Checking if the previous longest sequence for this rest is not longer.
                    if (outputMatrix[subSubIndex][subIndex] >= maxSizeByRest[(subIndex+inputVector[index]) % divider])
                    {
                        outputMatrix[index][(subIndex+inputVector[index]) % divider] = outputMatrix[subSubIndex][subIndex] + 1;
                    
                        // Update the longest subsequence for this rest.
                        maxSizeByRest[(subIndex+inputVector[index]) % divider] = outputMatrix[subSubIndex][subIndex] + 1;
                    }
                    // No need to write the value at the end of the loop
                    valueFoundOnColumn = true;

                    // Updating the longestSubsequenceByRest vector.
                    break;
                }
            }

            // If no value is found on this column, we start by this value.
            if ((!valueFoundOnColumn) && (0 == subIndex))
            {
                outputMatrix[index][(subIndex+inputVector[index]) % divider] = 1;
            }
        }
    }
    return outputMatrix;
}

/// @brief Retrieve the longest subsequence according that can be divided by the divider
/// @param originalVector Original Vector hat contains the sequence.
/// @param inputMatrix Matrix that contains rests from the calculus.
/// @param divider Value of the number that must divide the output sequence.
/// @return Vector of n lines, 2 columns. N lines : length of the subsequence, 2 columns : Indexes of the element from the original subsequence
std::vector<std::vector<int>> findLongestSequenceFromMatrix(const std::vector<int> originalVector, const std::vector<std::vector<int>> inputMatrix, int divider)
{
    // Retrieve the dimensions of the matrix.
    int numberOfLines = inputMatrix.size();
    int numberOfColumns = inputMatrix[0].size();

    // Instantiation of the outputVector
    std::vector<std::vector<int>> outputVector ;

    // Checking if the input matrix is not empty.
    if (0 == numberOfLines)
    {
        return {};
    }

    // First, we will search for the longest subsequence with a null-rest.
    int searchedRest = 0;

    // Iterating among all lines to get back the subsequence, by looking at the rests.
    for (int index = numberOfLines - 1; 0 <= index; index--)
    {
        // If the element appears on the line, we have to add it on the subsequence.
        if (0 != inputMatrix[index][searchedRest])
        {
            outputVector.push_back({originalVector[index], index});

            // Update the searched rest.
            searchedRest = (searchedRest - originalVector[index]) % divider;

            // We want a positive rest.
            if (0 > searchedRest)
            {
                searchedRest += divider;
            }
        }
    }

    return outputVector;
}

/// @brief Function that gets interesting data from an input file.
/// @param intputFileName Name of the file where data are written.
/// @param outputVector Sequence that we will work on.
/// @return Vector containing two elements : vector size, the divider.
std::vector<int> getDataFromTextFile_Exo3(const std::string intputFileName, std::vector<int> &outputVector)
{
    // Instanciation of the returned value.
    std::vector<int> returnedValue ;
    
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
        std::string firstLineFromInput, secondLineFromInput;

        // Create the string that contains tokens from the original string
        std::string token;

        // Retrieve both lines
        getline(readingFile, firstLineFromInput);
        getline(readingFile, secondLineFromInput);

        // Constructing stream from the first line
        std::stringstream stringStreamFirstLine(firstLineFromInput);

        // Getting vector size and divider
        getline(stringStreamFirstLine, token, ' ');
        returnedValue.push_back(std::stoi(token));
        getline(stringStreamFirstLine, token, ' ');
        returnedValue.push_back(std::stoi(token));

        // Constructing stream from the second line
        std::stringstream stringStreamSecondLine(secondLineFromInput);

        // Looping while i can get another int
        while (getline(stringStreamSecondLine, token, ' '))
        {
            // Store token string in the vector
            outputVector.push_back(std::stoi(token));
        }

        // If the number of the first line is smaller than the size of the vector, we have to get a sub vector :
        // The size has to be positive
        if (0 < returnedValue[0])
        {
            // We will loop only if some elements are not taken into account.
            for (int index = outputVector.size(); returnedValue[0] < index; index--)
            {
                outputVector.pop_back();
            }
        } 
        // Closing the file because we do not need it anymore.
        readingFile.close();
    }
    return returnedValue;
}

/// @brief Write data into a text file
/// @param indexOfVectorToWrite Vector containing : 1. Values of the sequence that gives the longest subsequence that can be divided by a given divider, 2. Indexes
/// @param outputFileName Name of the file we want to create.
void writeDataIntoTextFile_Exo3(const std::vector<std::vector<int>> indexOfVectorToWrite, const std::string outputFileName)
{
    // Instantiation of a fstream object which is a file.
	std::fstream writingFile;

    // Choose an input folder name and concatenate it to the name of the file.
    std::string inputFolderName = "textFiles/";
    std::string intputFileToRead = inputFolderName + outputFileName;

	// Opening the file in reading mode.
	writingFile.open(intputFileToRead, std::ios::out);

    // Total sum
    int sum = 0;

	// Checking if the file is correctly opened.
	if (writingFile.is_open())
	{
        // Writing the size of the subsequence
        writingFile << indexOfVectorToWrite[0].size() << std::endl;

		// Iterating among all students.
		for (std::vector<int> subVector : indexOfVectorToWrite)
		{
			// Writing in the terminal the textFile information concerning the current student.
			writingFile << "a[" << subVector[1] << "] = " << subVector[0] << std::endl;
            sum += subVector[0];
		}
        // Writing the result of the sum
		writingFile << "Sum = " << sum;

		// Closing the file because we do not need it anymore.
		writingFile.close();
	}
}