#include "./exo6.hpp"

using namespace std;


vector<int> matrixCompute(vector<int> input){
	int nodes_n = input[0];//get number of nodes
	int edges_n = input[1]; //get number of edges
	int start = input[2]; //get starting node
	int end = input[3];   //get ending node

	vector<vector<int>> matrix; //Initiate adjacence matrix

	int i,j;  //Initiate loop variables

        //Inialise Matrix values  
	for (i=0;i<nodes_n;i++){
		matrix.push_back({});
		for(j=0;j<nodes_n;j++){
			matrix[i].push_back( std::numeric_limits<int>::max());
		}
	}

        //Fill Matrix with Edges
	for(i=1;i<edges_n+1;i++){
		matrix[(input)[i*3+1]-1][(input)[i*3+2]-1] = (input)[i*3+3];
		matrix[(input)[i*3+2]-1][(input)[i*3+1]-1] = (input)[i*3+3];
	}

        //Create variables
	vector<int> distances = vector<int>(nodes_n, std::numeric_limits<int>::max());
	vector<int> previous = vector<int>(nodes_n, -1);
	
	//Initialize distance for start
	distances[start - 1] = 0;

        //Create Set to keep the node to process
	std::set<pair<int, int>> toVisit;
	toVisit.insert({0, start - 1});

	while (!toVisit.empty()) {    //While there's node to process
		int current = toVisit.begin()->second;  //Get info of node to process
		toVisit.erase(toVisit.begin()); //Remove from set

		for (int k = 0; k < nodes_n; k++) {   //Loop nodes_n times
			if (matrix[current][k] != std::numeric_limits<int>::max()) {    //If node k is neighbor of current node
				int dist = distances[current] + matrix[current][k];   //Compute planned distance
				if (dist < distances[k]) {            //Compare planned and current distance for node k
					toVisit.erase({distances[k], k}); //erase node from set
					distances[k] = dist;        //Replace the distance
					previous[k] = current;      //Keep track of previous node for the path
					toVisit.insert({dist, k});  //Reput the node in set
				}
			}
		}
	}

	vector<int> ret;      //Return vector
	
	for (int at = end - 1; at != -1; at = previous[at]) {   //Follow the previous vector to retrieve the path
		ret.push_back(at + 1);      //Write the path from end to begin
	}
	ret.push_back(distances[end-1]);    //Write distance of the path at the end
	
	std::reverse(ret.begin(), ret.end());   //Reverse the vector

	return ret;   //Return vector
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
