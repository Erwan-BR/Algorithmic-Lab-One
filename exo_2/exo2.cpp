#include "./exo2.hpp"

/// @brief Retrieve the longest increasing sequence from an input vector
/// @param inputVector Vector whose largest increasing sub-sequence is desired
/// @return Largest ascending subsequence.
std::vector<int> getLongestIncreasingSequenceIndexes(const std::vector<int>& inputVector)
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

    // Retrieve the index of the longest increasing subsequence
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

/// @brief Get a subsequence from a vector, according to the desired indexes to keep.
/// @param vectorToRetrieve Vector whose indexes are to be kept.
/// @param listOfIndexes Index to kep from vectorToRetrieve
/// @return Subsequence from the input vector
std::vector<int> getSequenceFromIndex(const std::vector<int> &vectorToRetrieve, const std::vector<int> &listOfIndexes)
{
    std::vector<int> outputVector;
    
    // Iterating among all indexes to write.
    for (int index : listOfIndexes)
    {
        // Checking if the value can be an index.
        // Should never happpen, but i's here for security.
        if (0 > index && (int)vectorToRetrieve.size() < index)
        {
            std::cout << "An error occured" << std::endl;
            return {};
        }
        // Adding the value to the desired vector
        outputVector.push_back(vectorToRetrieve[index]);
    }
    return outputVector;
}

/// @brief Retrieve the sequence whose largest increasing sub-sequence is desired
/// @param intputFileName Name of the file where the sequence is stored
/// @return Vector whose largest increasing sub-sequence is desired
std::vector<int> getDataFromTextFile_Exo2(const std::string intputFileName)
{
    // Instanciation of the returned vector.
    std::vector<int> outputVector;

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
        long unsigned int desiredSize = std::stoul(lineFromInputText);

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
        if (0 < desiredSize)
        {
            for (long unsigned int index = outputVector.size(); desiredSize < index; index--)
            {
                outputVector.pop_back();
            }
        }

        // Closing the file because we do not need it anymore.
        readingFile.close();
    }
    return outputVector;
}

/// @brief Write information concerning the longest subsequence into the output file
/// @param vectorToWrite Longest increasing subsequence
/// @param originalIndexes Indexes of the elements of the longest subsequence found
/// @param outputFileName Name of the file to save
void writeDataIntoTextFile_Exo2(const std::vector<int> vectorToWrite, const std::vector<int> originalIndexes, const std::string outputFileName)
{
    // Checking if both vectors are the same size. It's to add security, they should always have the same size.
    if (vectorToWrite.size() != originalIndexes.size())
    {
        std::cout << "An error occured." << std::endl;
        return ;
    }

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
        writingFile << vectorToWrite.size() << std::endl;

		// Iterating among all students.
		for (long unsigned int index = 0; index < vectorToWrite.size(); index++)
		{
			// Writing in the terminal the textFile information concerning the current student.
            // Adding 1 because mathematical table and informatical table are not the same.
			writingFile << "a[" << originalIndexes[index] + 1 << "] = " << vectorToWrite[index] << std::endl;
		}
		// Closing the file because we do not need it anymore.
		writingFile.close();
	}
}