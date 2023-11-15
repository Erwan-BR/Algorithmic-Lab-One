#include "./mainQuestion4.hpp"

void mainQuestion4()
{
	// Retrieving data from the input file
    vector<int> inputVector = getDataFromTextFile_Exo4("INP_ARB_GRAPH.txt");
	
	// Find a spanning tree for the graph with the matrix approach
	vector<int> outputMatrix = matrixCompute_Exo4(inputVector);
	// Writing data in an output file
	writeDataIntoTextFile_Exo4(outputMatrix,"OUT_ARB_GRAPH_MATRIX.txt");
    
	// Find a spanning tree for the graph with the list approach
	vector<int> outputList = listCompute_Exo4(inputVector);
	// Writing data in an output file
	writeDataIntoTextFile_Exo4(outputList,"OUT_ARB_GRAPH_LIST.txt");

	std::cout << "The output files, based on the input files, have been generated!" << std::endl;
}