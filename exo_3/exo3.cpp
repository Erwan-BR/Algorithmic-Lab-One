#include "./exo3.hpp"

std::vector<std::vector<int>> getMatrixOfRests(const std::vector<int> inputVector, int divider)
{
    // Creating the output Matrix which will be :
    // n columns (for the n values of the inputVector)
    // k lines (for the k possibles rests.)
    std::vector<std::vector<int>> outputMatrix;

    // Creation of the empty matrix (containing only zeros)
    for (int index = 0; index < inputVector.size(); index++)
    {
        outputMatrix.push_back({});
        for (int subIndex = 0; subIndex < divider; subIndex++)
        {
            outputMatrix[index].push_back(0);
        }
    }

    // Instanciation and initialization of a vector that ontains the longest subsequence possible
    // for a given rest.
    std::vector<int> maxSizeByRest;
    for (int index = 0; index < divider; index++)
    {
        maxSizeByRest.push_back(0);
    }

    // Initialization of the table
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
                    if (outputMatrix[subSubIndex][subIndex] <= maxSizeByRest[subIndex])
                    {
                        outputMatrix[index][(subIndex+inputVector[index]) % divider] = outputMatrix[subSubIndex][subIndex] + 1;
                    
                        // Update the longest subsequence for this rest.
                        maxSizeByRest[subIndex] = outputMatrix[subSubIndex][subIndex] + 1;
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

std::vector<int> findLongestSequenceFromMatrix(const std::vector<int> originalVector, const std::vector<std::vector<int>> inputMatrix, int divider)
{
    // Retrieve the dimensions of the matrix.
    int numberOfLines = inputMatrix.size();
    int numberOfColumns = inputMatrix[0].size();

    // Instantiation of the outputVector
    std::vector<int> outputVector ;

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
            outputVector.push_back(originalVector[index]);

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

std::vector<int> getDataFromInput_Exo3(const std::string intputFileName, std::vector<int> &outputVector)
{
    // Instanciation of the returned value.
    std::vector<int> returnedValue = {};
    
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
        // 1 : contains the size and the value to divide by.
        // 2 : contains the list, separated by spaces

        // Create the string that contains tokens from the original string
        std::string token;

        // Retrieve the first line
        getline(readingFile, lineFromInputText);

        // constructing stream from the string
        std::stringstream ss(lineFromInputText);
        
        // Getting both values.
        getline(ss, token, ' ');
        returnedValue.push_back(std::stoi(token));
        getline(ss, token, ' ');
        returnedValue.push_back(std::stoi(token));

        // Retrieve the second line into lineFromInputText to have a vector.
        getline(readingFile, lineFromInputText);

        // Looping while i can get another int
        while (getline(ss, token, ' '))
        {
            // Store token string in the vector
            outputVector.push_back(std::stoi(token));
        }

        // If the number of the first line is smaller than the size of the vector, we have to get a sub vector :
        // The size has to be positive
        if (0 < returnedValue[1])
        {
            for (int index = outputVector.size(); returnedValue[1] < index; index--)
            {
                outputVector.pop_back();
            }
        }

        // Closing the file because we do not need it anymore.
        readingFile.close();
    }
    return returnedValue;
}

void writeDataIntotextFile_Exo3(const std::vector<int> indexOfVectorToWrite, const std::string outputFileName)
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
        writingFile << indexOfVectorToWrite.size() << std::endl;

		// Iterating among all students.
		for (int index = 0; index < indexOfVectorToWrite.size(); index++)
		{
			// Writing in the terminal the textFile information concerning the current student.
			writingFile << "a[" << index << "] = " << indexOfVectorToWrite[index] << std::endl;
            sum += indexOfVectorToWrite[index];
		}
        // Writing the result of the sum
		writingFile << "Sum = " << sum << std::endl;

		// Closing the file because we do not need it anymore.
		writingFile.close();
	}
}