#include "./exo6.hpp"

using namespace std;

/// @brief Find the shortest path between two nodes. Nodes are precised in the input vector.
/// @param input Length of the path
/// @return Shortest path
vector<int> matrixCompute_Exo6(vector<int> input)
{
	int nodes_n = input[0];		//get number of nodes
	int edges_n = input[1];		//get number of edges
	int start = input[2];		//get starting node
	int end = input[3];			//get ending node

	//Initiate adjacence matrix
	vector<vector<int>> matrix(nodes_n, vector<int>(nodes_n, numeric_limits<int>::max()));

	// Fill Matrix with Edges
	for(int i = 1; i < edges_n+1; i++)
	{
		matrix[(input)[i*3+1]-1][(input)[i*3+2]-1] = (input)[i*3+3];
		matrix[(input)[i*3+2]-1][(input)[i*3+1]-1] = (input)[i*3+3];
	}

	//Create variables
	vector<int> distances = vector<int>(nodes_n, numeric_limits<int>::max());
	vector<int> previous = vector<int>(nodes_n, -1);
	
	//Initialize distance for start
	distances[start - 1] = 0;

	//Create Set to keep the node to process
	set<pair<int, int>> toVisit;
	toVisit.insert({0, start - 1});

	//While there's node to process
	while (!toVisit.empty())
	{
		int current = toVisit.begin()->second;		//Get info of node to process
		toVisit.erase(toVisit.begin());				// Remove from set

		//Loop nodes_n times
		for (int k = 0; k < nodes_n; k++)
		{
			//If node k is neighbor of current node
			if (matrix[current][k] != numeric_limits<int>::max())
			{
				int dist = distances[current] + matrix[current][k];   //Compute planned distance
				
				//Compare planned and current distance for node k
				if (dist < distances[k])
				{
					// Erase node from set
					toVisit.erase({distances[k], k});
					// Replace the distance
					distances[k] = dist;
					//Keep track of previous node for the path       
					previous[k] = current;
					//Re-put the node in set
					toVisit.insert({dist, k});
				}
			}
		}
	}
	// Return vector
	vector<int> ret;      
	
	// Follow the previous vector to retrieve the path
	for (int at = end - 1; at != -1; at = previous[at])
	{
		// Write the path from end to begin
		ret.push_back(at + 1);
	}

	// Write distance of the path at the end
	ret.push_back(distances[end-1]);
	
	// Reverse the vector
	reverse(ret.begin(), ret.end());

	return ret;
}

/// @brief Retrieve data from the input file
/// @param inputFileName Name of the file to look for
/// @return Vector that is used in the exercised
vector<int> getDataFromTextFile_Exo6(string inputFileName)
{
    // Variables to retrieve from the line.
    vector<int> outputVector ;

    // Instantiation of a fstream object which is a file.
	fstream readingFile;

	// Choose an input folder name and concatenate it to the name of the file.
	string inputFolderName = "textFiles/";
	string inputFileToRead = inputFolderName + inputFileName;

	// Opening the file in reading mode.
	readingFile.open(inputFileToRead, ios::in);

	// Checking if the file is correctly opened.
	if (readingFile.is_open())
	{
        // Instantiation of a string that will represent the line in the document.
        string lineFromInputText;

        // Create the string that contains tokens from the original string
        string token;

        stringstream ss;

        // Retrieve lines into lineFromInputText
        while(getline(readingFile, lineFromInputText))
		{
			// constructing stream from the string
			ss = stringstream(lineFromInputText);

			// Looping while i can get another int
			while (getline(ss, token, ' '))
			{
				// Store token string in the vector
				outputVector.push_back(stoi(token));
			}
        }

        // Closing the file because we do not need it anymore.
        readingFile.close();
    }
    return outputVector;
}

/// @brief Wirte data into the output text file
/// @param vectorToWrite Vector to write in the text file
/// @param outputFileName Name of the file that will be created
void writeDataIntoTextFile_Exo6(vector<int> vectorToWrite, string outputFileName)
{
    // Instantiation of a fstream object which is a file.
	fstream writingFile;

	// Choose an input folder name and concatenate it to the name of the file.
	string outputFolderName = "textFiles/";
	string outputFileToRead = outputFolderName + outputFileName;

	// Opening the file in reading mode.
	writingFile.open(outputFileToRead, ios::out);

	// Checking if the file is correctly opened.
	if (writingFile.is_open())
	{
		// Header of the output file
		writingFile << vectorToWrite[0] << endl;
		writingFile << vectorToWrite[1];
		
		// Adding the sequence
		for (long unsigned int i = 2; i < vectorToWrite.size(); i++)
		{
			writingFile << " -> " << to_string(vectorToWrite[i]);
		}
		writingFile <<endl;
		// Closing the file because we do not need it anymore.
		writingFile.close();
	}
}
