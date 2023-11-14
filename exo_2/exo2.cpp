#include "./exo2.hpp"

std::vector<int> getLongestIncreasingSequence(const std::vector<int>& inputVector)
{
    // Get the size of the vector
    int inputVectorSize = inputVector.size();

    // If the vector is empty, nothing to return.
    if (0 == inputVectorSize)
    {
        return {};
    }

    // Two vectors needed :
    // 1. Store the max len you can have with a certain value.
    std::vector<int> maxSizeFromValue(inputVectorSize, 1);

    // 2. Store the index of the previous element that correspond to the longest increasing sequence
    std::vector<int> previousIndexForSubsequence(inputVectorSize, -1);

    // Two int needed :
    // 1. The maxLength ever obtained
    int maxLength = 1;
    // 2. The index of the end of the sequence.
    int endIndex = 0;

    // Iterating among all elements of the inputVector
    for (int i = 1; i < inputVectorSize; ++i)
    {
        // Iterating among all values before the one we are looking for.
        for (int j = 0; j < i; ++j)
        {
            // Checking if the current value is greater AND if the size obtained is smaller than the one we can have with another value.
            if (inputVector[i] > inputVector[j] && maxSizeFromValue[i] < maxSizeFromValue[j] + 1)
            {
                maxSizeFromValue[i] = maxSizeFromValue[j] + 1;
                previousIndexForSubsequence[i] = j;

                // If we found a new longest sequence, we change the content of the maxLength and the index of the end
                if (maxSizeFromValue[i] > maxLength)
                {
                    maxLength = maxSizeFromValue[i];
                    endIndex = i;
                }
            }
        }
    }

    std::vector<int> longestSubsequenceIndexes = {endIndex};
    while (endIndex != -1)
    {
        longestSubsequenceIndexes.insert(longestSubsequenceIndexes.begin(), previousIndexForSubsequence[endIndex]);
        endIndex = previousIndexForSubsequence[endIndex];
    }

    // Returning the list of index needed to get the values of the Longest Increasing Subsequence without -1.
    longestSubsequenceIndexes.erase(longestSubsequenceIndexes.begin());

    return longestSubsequenceIndexes;
}

int getDataFromInput(const std::string intputFileName, std::vector<int> &outputVector)
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

        // If the number of the first line is smaller than the size of the vector, we have to get a sub vector :
        // The size has to be positive
        if (0 < returnedValue)
        {
            for (int index = outputVector.size(); returnedValue < index; index--)
            {
                outputVector.pop_back();
            }
        }

        // Closing the file because we do not need it anymore.
        readingFile.close();
    }
    return returnedValue;
}

void writeDataIntotextFile(const std::vector<int> indexOfVectorToWrite, const std::string outputFileName)
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
        // Writing the size of the subsequence
        writingFile << indexOfVectorToWrite.size() << std::endl;

		// Iterating among all students.
		for (int index = 0; index < indexOfVectorToWrite.size(); index++)
		{
			// Writing in the terminal the textFile information concerning the current student.
			writingFile << "a[" << index + 1 << "] = " << indexOfVectorToWrite[index] << std::endl;
		}
		// Closing the file because we do not need it anymore.
		writingFile.close();
	}
}