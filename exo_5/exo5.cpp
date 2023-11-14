#include "./exo5.hpp"

using namespace std;

/// @brief 
/// @param matrix 
/// @param comp 
/// @param processed 
/// @param node 
void matrixProcess(vector<vector<int>> matrix, vector<int>* comp, vector<int>* processed, int node)
{
	(*processed)[node-1] = 1;
	comp->push_back(node);
	int i, j;
	for (i=0; i<(matrix).size(); i++){
		if((matrix)[node-1][i] != 0 and not((*processed)[i]))
        {
			matrixProcess(matrix, comp, processed,i+1);
		}
	}
}

/// @brief 
/// @param input 
/// @return 
vector<vector<int>> matrixCompute(vector<int> input)
{
	int nodes_n = input[0];
	int edges_n = input[1];

	vector<vector<int>> matrix;
	vector<vector<int>> connex;

	int i, j;

	for (i=0; i<nodes_n; i++)
    {
		matrix.push_back({});
		for(j=0; j<nodes_n; j++)
        {
			matrix[i].push_back(0);
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

	bool all_processed = false;
	while(not all_processed)
    {
		all_processed = true;
		for(i=0; i<nodes_n; i++)
        {
			if(not processed[i])
            {
				all_processed = false;
				connex.push_back({});
				matrixProcess(matrix,&(connex.back()),&processed,i+1);
			}
		}
	}


	for (i=0; i<processed.size(); i++)
    {
		if(not processed[i]){
			cout << "Error - matrix : Not all nodes processed." << endl;
			return {{-1}};
		}
	}
	return connex;
}

/// @brief 
/// @param list 
/// @param comp 
/// @param processed 
/// @param node 
void listProcess(vector<vector<int>> list, vector<int>* comp, vector<int>* processed, int node)
{
	(*processed)[node-1] = 1;
	comp->push_back(node);
	for (int i : list[node-1])
    {
		if(not((*processed)[i]))
        {
			listProcess(list, comp, processed,i+1);
		}
	}
}

/// @brief 
/// @param input 
/// @return 
vector<vector<int>> listCompute(vector<int> input)
{
	int nodes_n = input[0];
	int edges_n = input[1];

	vector<vector<int>> list;
	vector<vector<int>> connex;
	int i, j;

	for (i=0; i<nodes_n; i++)
    {
		list.push_back({});
	}

	for(i=1;i<edges_n;i++)
    {
		list[(input)[i*2]-1].push_back((input)[i*2+1]-1);
		list[(input)[i*2+1]-1].push_back((input)[i*2]-1);
	}

	vector<int> processed;
	for (i=0;i<nodes_n;i++)
    {
		processed.push_back(0);
	}


	bool all_processed = false;
	while(not all_processed)
    {
		all_processed = true;
		for(i=0; i<nodes_n; i++)
        {
			if(not processed[i])
            {
				all_processed = false;
				connex.push_back({});
				listProcess(list,&(connex.back()),&processed,i+1);
			}
		}
	}

	for (i=0; i<processed.size(); i++)
    {
		if(not processed[i])
        {
			cout << "Error - matrix : Not all nodes processed." << endl;
			return {{-1}};
		}
	}
	return connex;
}

/// @brief 
/// @param intputFileName 
/// @return 
std::vector<int> getVectorFromInput_Exo5(std::string intputFileName)
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
void writeVectorIntotextFile_Exo5(std::vector<std::vector<int>> vectorToWrite, std::string outputFileName)
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
		writingFile << vectorToWrite.size() << endl;
		int i, j;
		for (i=0; i<vectorToWrite.size(); i++)
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
