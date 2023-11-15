#include "./mainQuestion6.hpp"

void mainQuestion6()
{
	vector<int> input;
	input = getVectorFromInput_Exo6("INP_DIJ_GRAPH.txt");
	int i;
	vector<int> output;
	output = matrixCompute(input);
	writeVectorIntotextFile_Exo6(output,"OUT_DIJ_GRAPH_MATRIX.txt");
}
