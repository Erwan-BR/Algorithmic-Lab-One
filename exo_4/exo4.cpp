#include "./exo4.hpp"

#include <iostream>
#include <string>

using namespace std;

/// @brief 
/// @param matrix 
/// @param tree 
/// @param processed 
/// @param node 
void matrixProcess(vector<vector<int>> matrix, vector<vector<int>>* tree, vector<int>* processed, int node)
{
	(*processed)[node-1] = 1;

	int i, j;
	for (i=0; i<(matrix).size(); i++)
	{
		if((matrix)[node-1][i] != 0 and not((*processed)[i]))
		{
			(*tree)[node-1][i] = 1;
			(*tree)[i][node-1] = 1;
			matrixProcess(matrix, tree, processed, i+1);
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

	vector<vector<int>> matrix;
	vector<vector<int>> tree;
	int i, j;

	for (i=0; i<nodes_n; i++)
	{
		matrix.push_back({});
		tree.push_back({});
		for(j=0; j<nodes_n; j++)
		{
			matrix[i].push_back(0);
			tree[i].push_back(0);
		}
	}

	for(i=1; i<edges_n; i++)
	{
		matrix[(input)[i*2]-1][(input)[i*2+1]-1] += 1;
		matrix[(input)[i*2+1]-1][(input)[i*2]-1] += 1;
	}

	vector<int> processed;
	for (i=0; i<nodes_n; i++)
	{
		processed.push_back(0);
	}
	int starting_node = 1;

	matrixProcess(matrix, &tree, &processed, starting_node);

	for (i=0; i<processed.size(); i++)
	{
		if(not processed[i])
		{
			cout << "Error - matrix : Not all nodes processed." << endl;
			return {-1};
		}
	}

	vector<int> edges;
	int new_edges_n=0;
	for (i=0; i<nodes_n; i++)
	{
		for(j=i; j<nodes_n; j++)
		{
			if(0!= tree[i][j])
			{
				edges.push_back(i+1);
				edges.push_back(j+1);
				new_edges_n++;
			}
		}
	}
	if(new_edges_n != nodes_n-1)
	{
		cout << "Error - matrix : Not enough edges.("<<to_string(new_edges_n)<<")" << endl;
		return {-1};
	}
	else
	{
		return edges;
	}
}

/// @brief 
/// @param list 
/// @param tree 
/// @param processed 
/// @param node 
void listProcess(vector<vector<int>> list, vector<vector<int>>* tree, vector<int>* processed, int node)
{
	(*processed)[node-1] = 1;

	for (int i : list[node-1])
	{
		if(not((*processed)[i]))
		{
			((*tree)[node-1]).push_back(i+1);
			((*tree)[i]).push_back(node);
			listProcess(list, tree, processed, i+1);
		}
	}
}

/// @brief 
/// @param input 
/// @return 
vector<int> listCompute(vector<int> input)
{
	int nodes_n = input[0];
	int edges_n = input[1];

	vector<vector<int>> list;
	vector<vector<int>> tree;
	int i, j;

	for (i=0; i<nodes_n; i++)
	{
		list.push_back({});
		tree.push_back({});
	}

	for(i=1; i<edges_n; i++)
	{
		list[(input)[i*2]-1].push_back((input)[i*2+1]-1);
		list[(input)[i*2+1]-1].push_back((input)[i*2]-1);
	}

	vector<int> processed;
	for (i=0;i<nodes_n;i++)
	{
		processed.push_back(0);
	}
	int starting_node = 1;

	listProcess(list, &tree, &processed, starting_node);

	for (i=0; i<processed.size(); i++)
	{
		if(not processed[i])
		{
			cout << "Error - matrix : Not all nodes processed." << endl;
			return {-1};
		}
	}

	vector<int> edges;
	int new_edges_n = 0;
	for (i=0; i<nodes_n; i++)
	{
		for(int k : tree[i])
		{
			if(i+1 < k)
			{
				edges.push_back(i+1);
				edges.push_back(k);
				new_edges_n++;
			}
		}
	}
	if(new_edges_n != nodes_n-1)
	{
		cout << "Error - matrix : Not enough edges.(" << to_string(new_edges_n) << ")" << endl;
		return {-1};
	}
	else
	{
		return edges;
	}
}

/// @brief 
/// @param intputFileName 
/// @return 
std::vector<int> getVectorFromInput(std::string intputFileName)
{
    // Variables to retrieve from the line.
    std::vector<int> outputVector ;

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

        // Create the string that contains tokens from the original string
        std::string token;

        std::stringstream ss;

        // Retrieve lines into lineFromInputText
        while(std::getline(readingFile, lineFromInputText)){

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
void writeVectorIntotextFile(std::vector<int> vectorToWrite, std::string outputFileName)
{
    // Instantiation of a fstream object which is a file.
	std::fstream writingFile;

	// Choose an input folder name and concatenate it to the name of the file.
    std::string outputFolderName = "textFiles/";
    std::string outputFileToWrite = outputFolderName + outputFileName;

	// Opening the file in reading mode.
	writingFile.open(outputFileToWrite, std::ios::out);

	// Checking if the file is correctly opened.
	if (writingFile.is_open())
	{
		// Iterating among all students.
		int i;
		for (i=0;i<vectorToWrite.size();i++)
		{
			// Writing in the terminal the textFile information concerning the current student.
			writingFile << vectorToWrite[i];

			if (i%2) {writingFile << endl;}
			else {writingFile << " ";}
		}
		// Closing the file because we do not need it anymore.
		writingFile.close();
	}
}
