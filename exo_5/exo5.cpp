#include "./exo5.hpp"

using namespace std;

/// @brief Take a matrix to go through a node
/// @param matrix Matrix of the exercise
/// @param comp Connex component currently retrieved
/// @param processed Vector that states which node are processed
/// @param node Node to process
void matrixProcess_Exo5(vector<vector<int>> matrix, vector<int>* comp, vector<bool>* processed, int inputNode)
{
	// Writing that the node is already viewed.
	(*processed)[inputNode-1] = true;
	
	// Adding the node to the current connex part.
	comp->push_back(inputNode);

	// Go through every node
	for (long unsigned int i = 0; i < (matrix).size(); i++)
	{
		// Checking if the node i is not already process (to add it to the currernt comnnex component)
		if((0 != (matrix)[inputNode-1][i])  && !((*processed)[i]))
        {
			// Process the new node
			matrixProcess_Exo5(matrix, comp, processed, i+1);
		}
	}
}

/// @brief Find all convexe parts of the given vector
/// @param input Vector that contains the elements of the text file
/// @return Matrix that contains multiple convexe part
vector<vector<int>> matrixCompute_Exo5(vector<int> input)
{
	// Checking if the input vector is not empty or too small.
	if (1 > input.size())
	{
		return {{-1}};
	}

	// Retrieve size from the input vector 
	int nodes_n = input[0];
	int edges_n = input[1];

	// Intanciation of two vectors : matrix that contains all elements, connex that contains all connex parts.
	vector<vector<int>> matrix(nodes_n, vector<int>(nodes_n, 0));
	vector<vector<int>> connex;

	// Writing the values that are on the inputFile.
	for(int index = 1; index < edges_n; index++)
    {
		matrix[(input)[index*2]-1][(input)[index*2+1]-1] += 1;
		matrix[(input)[index*2+1]-1][(input)[index*2]-1] += 1;
	}

	// Initialisation of a vector that will inform if a given node is processed (added to a connex component) or not.
	vector<bool> processed(nodes_n, false);

	// Boolean that checked if all nodes are processed.
	bool all_processed = false;
	
	// Looping while at least one node is not processed.
	while(!all_processed)
    {
		all_processed = true;
		
		// Iterating among all nodes
		for(int index = 0; index < nodes_n; index++)
        {
			// Checking if the node is processed. If not, we just found a new connex part !
			if(!processed[index])
            {
				// Setting that all component parts are not set.
				all_processed = false;
				
				// Adding a new empty connex part
				connex.push_back({});

				// Filling the new connex part
				matrixProcess_Exo5(matrix, &(connex.back()), &processed, index+1);
			}
		}
	}
	// Security : Checking that all elements are processed.
	// We should never enter in the nested if.
	for (long unsigned int i = 0; i < processed.size(); i++)
    {
		// If at least one element is not porocessed, return an error message.
		if(!processed[i])
		{
			cout << "Error - matrix : Not all nodes processed." << endl;
			return {{-1}};
		}
	}
	return connex;
}

/// @brief Take a list to go through a node
/// @param list List of the exercise
/// @param comp Connex component currently retrieved
/// @param processed Vector that states which node are processed
/// @param node Node to process
void listProcess_Exo5(vector<vector<int>> list, vector<int>* comp, vector<bool>* processed, int node)
{
	// Writing that the node is already viewed.
	(*processed)[node-1] = true;
	
	// Adding the node to the current connex part.
	comp->push_back(node);
	
	// Go through every node
	for (int i : list[node-1])
    {
		// Checking if the node i is not already process (to add it to the currernt comnnex component)
		if(!((*processed)[i]))
        {
			// Process the new node
			listProcess_Exo5(list, comp, processed, i+1);
		}
	}
}

/// @brief Find all convexe parts of the given vector
/// @param input Vector that contains the elements of the text file
/// @return Matrix that contains multiple convexe part
vector<vector<int>> listCompute_Exo5(vector<int> input)
{
	// Checking if the input vector is not empty or too small.
	if (1 > input.size())
	{
		return {{-1}};
	}

	// Retrieve size from the input vector 
	int nodes_n = input[0];
	int edges_n = input[1];

	// Intanciation of two vectors : matrix that contains all elements, connex that contains all connex parts.
	vector<vector<int>> list(nodes_n, vector<int>());
	vector<vector<int>> connex;

	// Writing the values that are on the inputFile.
	for(int index = 1; index < edges_n; index++)
    {
		list[(input)[index*2]-1].push_back((input)[index*2+1]-1);
		list[(input)[index*2+1]-1].push_back((input)[index*2]-1);
	}

	// Initialisation of a vector that will inform if a given node is processed (added to a connex component) or not.
	vector<bool> processed(nodes_n, false);

	// Boolean that checked if all nodes are processed.
	bool all_processed = false;

	// Looping while at least one node is not processed.
	while(!all_processed)
    {
		all_processed = true;
		
		// Iterating among all nodes
		
		for(int index = 0; index < nodes_n; index++)
        {
			// Checking if the node is processed. If not, we just found a new connex part !
			
			if(!processed[index])
            {
				// Setting that all component parts are not set.
				all_processed = false;
				
				// Adding a new empty connex part
				connex.push_back({});

				// Filling the new connex part
				listProcess_Exo5(list, &(connex.back()), &processed, index+1);
			}
		}
	}

	// Security : Checking that all elements are processed.
	// We should never enter in the nested if.
	for (long unsigned int i = 0; i < processed.size(); i++)
    {
		// If at least one element is not processed, return an error message.
		if(!(processed[i]))
        {
			cout << "Error - matrix : Not all nodes processed." << endl;
			return {{-1}};
		}
	}
	return connex;
}

/// @brief Construct a vector based on the content of an input file
/// @param intputFileName Name of the file we want to open
/// @return Input vector for the exercise
vector<int> getDataFromTextFile_Exo5(string intputFileName)
{
    // Variables to retrieve from the line.
    vector<int> outputVector ;

    // Instantiation of a fstream object which is a file.
	fstream readingFile;

	// Choose an input folder name and concatenate it to the name of the file.
    string inputFolderName = "textFiles/";
    string intputFileToRead = inputFolderName + intputFileName;

	// Opening the file in reading mode.
	readingFile.open(intputFileToRead, ios::in);

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

/// @brief Write the different connexe part into a text file.
/// @param vectorToWrite Vector to export
/// @param outputFileName Name of the file we want to generate
void writeDataIntoTextFile_Exo5(vector<vector<int>> vectorToWrite, string outputFileName)
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
		writingFile << vectorToWrite.size() << endl;
		
		// Writing all connex components of the vector to write.
		for (long unsigned int i = 0; i < vectorToWrite.size(); i++)
		{
			writingFile << "Composante Connexe " << to_string(i+1) << " :" <<endl;
			for(int j : vectorToWrite[i])
            {
				// Writing in the terminal the textFile information concerning the current student.
				writingFile << to_string(j) << " ";
			}
			writingFile <<endl;
		}
		// Closing the file because we do not need it anymore.
		writingFile.close();
	}
}