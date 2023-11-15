#include "./mainQuestion6.hpp"

void mainQuestion6()
{
	// Get the vector from the input file
	std::vector<int> inputVector = getDataFromTextFile_Exo6("INP_DIJ_GRAPH.txt");

	// Retrieve the output vector
	std::vector<int> outputVector = matrixCompute_Exo6(inputVector);

	// Write the shortests path into a text file
	writeDataIntoTextFile_Exo6(outputVector, "OUT_DIJ_GRAPH_MATRIX.txt");

	std::cout << "The output file (for question 6.1), based on the input files, has been generated!" << std::endl;
}
