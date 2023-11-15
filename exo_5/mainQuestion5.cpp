#include "./mainQuestion5.hpp"

void mainQuestion5()
{
    vector<int> inputVector = getDataFromTextFile_Exo5("INP_CON_GRAPH.txt");
	
	vector<vector<int>> outputMatrix = matrixCompute_Exo5(inputVector);
	writeDataIntoTextFile_Exo5(outputMatrix,"OUT_CON_GRAPH_MATRIX.txt");
    
	vector<vector<int>> outputList = listCompute_Exo5(inputVector);
	writeDataIntoTextFile_Exo5(outputList,"OUT_CON_GRAPH_LIST.txt");

	std::cout << "The output files, based on the input files, have been generated!" << std::endl;
}