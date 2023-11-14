#include "./mainQuestion4.hpp"

void mainQuestion4()
{
    vector<int> input;
	input = getVectorFromInput_Exo4("INP_ARB_GRAPH.txt");
	
    int i;
	vector<int> output;

	output = matrixCompute(input);
	writeVectorIntotextFile_Exo4(output,"OUT_ARB_GRAPH_MATRIX.txt");
    
	output = listCompute(input);
	writeVectorIntotextFile_Exo4(output,"OUT_ARB_GRAPH_LIST.txt");
}