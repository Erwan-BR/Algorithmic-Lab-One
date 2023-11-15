#include "./exo4.hpp"

#include <iostream>
#include <string>

using namespace std;

/// @brief Take a matrix to go through a node
/// @param matrix Matrix of the exercise
/// @param tree Tree containing nodes
/// @param processed Vector that states which node are processed
/// @param inputNode Node to process.
void matrixProcess_Exo4(const vector<vector<int>> matrix, vector<vector<int>>* tree, vector<bool>* processed, int inputNode)
{
	// Writing that the node is already viewed.
	(*processed)[inputNode-1] = true;

	// Go through every node
	for (long unsigned int nodeIndex = 0; nodeIndex < matrix.size(); nodeIndex++)
	{
		// Checking if the node i and the inputnode is not already processed 
		if((matrix)[inputNode-1][nodeIndex] != 0 and not((*processed)[nodeIndex]))
		{
			// Writing in the tree matrix the edge
			(*tree)[inputNode-1][nodeIndex] = 1;
			(*tree)[nodeIndex][inputNode-1] = 1;

			// Process the new node
			matrixProcess_Exo4(matrix, tree, processed, nodeIndex+1);
		}
	}
}

/// @brief Compute the vector of edges
/// @param input Vector that contains the elements of the text file
/// @return Edges vector.
vector<int> matrixCompute_Exo4(vector<int> input)
{
	// Retrieve the number of nodes and edges.
	int nodes_n = input[0];
	int edges_n = input[1];

	// Construct matrix and tree
    vector<vector<int>> matrix(nodes_n, vector<int>(nodes_n, 0));
    vector<vector<int>> tree(nodes_n, vector<int>(nodes_n, 0));

	for(int i = 1; i < edges_n; i++)
	{
		matrix[(input)[i*2]-1][(input)[i*2+1]-1] += 1;
		matrix[(input)[i*2+1]-1][(input)[i*2]-1] += 1;
	}

	// Creating a processed vector that allows to know wether a value is processed or not.
	vector<bool> processed(nodes_n, false);
	
	// Starting the process with the 1st node
	int starting_node = 1;

	// Launch the process of the matrix.
	matrixProcess_Exo4(matrix, &tree, &processed, starting_node);

	// Security : Iterating among the processed vector to know if a value is not processed.
	// We should never enter if the nested if.
	for(int isProcessed : processed)
	{
		if (not isProcessed)
		{
			cout << "Error - matrix : Not all nodes processed." << endl;
			return {-1};
		}
	}

	vector<int> edges;
	int new_edges_n = 0;

	// Iterating on the tree (thanks to i and j) to find the number of edges.
	// Adding in the edges vector the element that we want to display.
	for (int i = 0; i < nodes_n; i++)
	{
		for(int j = i; j < nodes_n; j++)
		{
			// If we enter, it means that i+1 and j+1 nodes are adjacent.
			if(0!= tree[i][j])
			{
				edges.push_back(i+1);
				edges.push_back(j+1);
				new_edges_n++;
			}
		}
	}

	// Security : Checking if the number of edge is the correct one.
	// We should never enter inside.
	if(new_edges_n != nodes_n - 1)
	{
		cout << "Error - matrix : Not enough edges.(" << new_edges_n << ")" << endl;
		return {-1};
	}

	return edges;
}

/// @brief Take a matrix to go through a node
/// @param list List of the exercise
/// @param tree Tree containing nodes
/// @param processed Vector that states which node are processed
/// @param inputNode Node to process.
void listProcess_Exo4(vector<vector<int>> list, vector<vector<int>>* tree, vector<bool>* processed, int inputNode)
{
	// Writing that the node is already viewed.
	(*processed)[inputNode-1] = true;

	// Go through every node
	for (int i : list[inputNode-1])
	{
		// Checking if the node is not already processed.
		if(not((*processed)[i]))
		{
			// Writing in the tree matrix the edge
			((*tree)[inputNode-1]).push_back(i+1);
			((*tree)[i]).push_back(inputNode);

			// Process the new node
			listProcess_Exo4(list, tree, processed, i+1);
		}
	}
}

/// @brief Compute the vector of edges
/// @param input Vector that contains the elements of the text file
/// @return Edges vector.
vector<int> listCompute_Exo4(vector<int> input)
{
	// Retrieve the number of nodes and edges.
	int nodes_n = input[0];
	int edges_n = input[1];

	// Construct list and tree
	vector<vector<int>> list(nodes_n, vector<int>());
	vector<vector<int>> tree(nodes_n, vector<int>());

	for(int i = 1; i < edges_n; i++)
	{
		list[(input)[i*2]-1].push_back((input)[i*2+1]-1);
		list[(input)[i*2+1]-1].push_back((input)[i*2]-1);
	}
	
	// Creating a processed vector that allows to know wether a value is processed or not.
	vector<bool> processed(nodes_n, false);

	// Starting the process with the 1st node
	int starting_node = 1;

	// Launch the process of the matrix.
	listProcess_Exo4(list, &tree, &processed, starting_node);

	// Security : Iterating among the processed vector to know if a value is not processed.
	// We should never enter if the nested if.
	for (long unsigned int i = 0; i < processed.size(); i++)
	{
		if(not processed[i])
		{
			cout << "Error - matrix : Not all nodes processed." << endl;
			return {-1};
		}
	}

	vector<int> edges;
	int new_edges_n = 0;

	// Iterating on the tree (thanks to i and j) to find the number of edges.
	// Adding in the edges vector the element that we want to display.
	for (int i = 0; i < nodes_n; i++)
	{
		for(int k : tree[i])
		{
			// If we enter, it means that nodes are adjacent.
			if(i+1 < k)
			{
				edges.push_back(i+1);
				edges.push_back(k);
				new_edges_n++;
			}
		}
	}
	// Security : Checking if the number of edge is the correct one.
	// We should never enter inside.
	if(new_edges_n != nodes_n-1)
	{
		cout << "Error - matrix : Not enough edges.(" << to_string(new_edges_n) << ")" << endl;
		return {-1};
	}
	
	return edges;
}

/// @brief 
/// @param intputFileName 
/// @return 
vector<int> getDataFromTextFile_Exo4(string intputFileName)
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

/// @brief 
/// @param vectorToWrite 
/// @param outputFileName 
void writeDataIntoTextFile_Exo4(vector<int> vectorToWrite, string outputFileName)
{
    // Instantiation of a fstream object which is a file.
	fstream writingFile;

	// Choose an input folder name and concatenate it to the name of the file.
    string outputFolderName = "textFiles/";
    string outputFileToWrite = outputFolderName + outputFileName;

	// Opening the file in reading mode.
	writingFile.open(outputFileToWrite, ios::out);

	// Checking if the file is correctly opened.
	if (writingFile.is_open())
	{
		// Iterating among all students.
		for (long unsigned int i = 0; i < vectorToWrite.size(); i++)
		{
			// Writing in the terminal the textFile information concerning the current student.
			writingFile << vectorToWrite[i];

			if (i%2)
			{
				writingFile << endl;
			}
			else
			{
				writingFile << " ";
			}
		}
		// Closing the file because we do not need it anymore.
		writingFile.close();
	}
}
