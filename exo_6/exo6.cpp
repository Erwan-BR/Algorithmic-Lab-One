#include "./exo6.hpp"

using namespace std;

/// @brief 
/// @param matrix 
/// @param distances 
/// @param previous 
/// @param node 
/// @param distance 
void matrixProcess(vector<vector<int>> matrix, vector<int>* distances, vector<int>* previous, int node, int distance)
{
	
	(*distances)[node-1] = distance;

	int i, j;
	for (i = 0; i < matrix.size(); i++)
	{
		if((distance + matrix[node - 1][i]) < (*distances)[i] && -1 != matrix[node-1][i])
		{
			(*previous)[i] = node;
			matrixProcess(matrix, distances, previous, i+1, distance + matrix[node - 1][i]);
		}
	}
}

/// @brief 
/// @param input 
/// @return 
vector<int> matrixCompute(vector<int> input)
{
	int nodes_n = input[0];
	int edges_n = input[1];
	int start = input[2];
	int end = input[3];

	vector<vector<int>> matrix;
	vector<int> ret;

	int i, j;

	for (i=0; i<nodes_n; i++)
	{
		matrix.push_back({});
		for(j=0; j<nodes_n; j++)
		{
			matrix[i].push_back(-1);
		}
	}

	for(i=1; i<edges_n; i++)
	{
		matrix[(input)[i*3]-1][(input)[i*3+1]-1] = (input)[i*3+2];
		matrix[(input)[i*3+1]-1][(input)[i*3]-1] = (input)[i*3+2];
	}

	vector<int> distances;
	vector<int> previous;
	for (i=0; i<nodes_n; i++)
	{
		distances.push_back(-1);
		previous.push_back(0);
	}


	matrixProcess(matrix, &distances, &previous, start+1, 0);


	i = end - 1;
	while(0 != distances[i])
	{
		i = previous[i];
		ret.insert(ret.begin(), i+1);
	}
	ret.insert(ret.begin(), start);
	ret.insert(ret.begin(), distances[end-1]);

	return ret;
}

/// @brief 
/// @param inputFileName 
/// @return 
std::vector<int> getVectorFromInput_Exo6(std::string inputFileName)
{
    // Variables to retrieve from the line.
    std::vector<int> outputVector ;

    // Instantiation of a fstream object which is a file.
	std::fstream readingFile;

	// Choose an input folder name and concatenate it to the name of the file.
	std::string inputFolderName = "textFiles/";
	std::string inputFileToRead = inputFolderName + inputFileName;

	// Opening the file in reading mode.
	readingFile.open(inputFileToRead, std::ios::in);

	// Checking if the file is correctly opened.
	if (readingFile.is_open())
	{
        // Instantiation of a string that will represent the line in the document.
        std::string lineFromInputText;

        // Create the string that contains tokens from the original string
        std::string token;

        std::stringstream ss;

        // Retrieve lines into lineFromInputText
        while(std::getline(readingFile, lineFromInputText))
		{
			// constructing stream from the string
			ss = std::stringstream(lineFromInputText);

			// Looping while i can get another int
			while (getline(ss, token, ' '))
			{
				// Store token string in the vector
				outputVector.push_back(std::stoi(token));
			}
        }

        // Closing the file because we do not need it anymore.
        readingFile.close();
    }
    return outputVector;
}

/// @brief 
/// @param vectorToWrite 
/// @param outputFileName 
void writeVectorIntotextFile_Exo6(std::vector<int> vectorToWrite, std::string outputFileName)
{
    // Instantiation of a fstream object which is a file.
	std::fstream writingFile;

	// Choose an input folder name and concatenate it to the name of the file.
	std::string outputFolderName = "textFiles/";
	std::string outputFileToRead = outputFolderName + outputFileName;

	// Opening the file in reading mode.
	writingFile.open(outputFileToRead, std::ios::out);

	// Checking if the file is correctly opened.
	if (writingFile.is_open())
	{
		writingFile << to_string(vectorToWrite[0]) << endl;
		int i;
		writingFile << to_string(vectorToWrite[1]);
		for (i=2; i<vectorToWrite.size(); i++)
		{
			writingFile << "->" << to_string(vectorToWrite[i]);

		}
		writingFile <<endl;
		// Closing the file because we do not need it anymore.
		writingFile.close();
	}
}
