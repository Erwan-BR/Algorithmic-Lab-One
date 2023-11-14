#include "./mainQuestion4.hpp"

void mainQuestion4()
{
    vector<int> input;
	input = getVectorFromInput("INP_ARB_GRAPH.txt");
	
    int i;
	vector<int> output;

	output = matrixCompute(input);
	writeVectorIntotextFile(output,"OUT_ARB_GRAPH_MATRIX.txt");
    
	output = listCompute(input);
	writeVectorIntotextFile(output,"OUT_ARB_GRAPH_LIST.txt");
}