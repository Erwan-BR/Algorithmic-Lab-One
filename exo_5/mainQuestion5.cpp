#include "./mainQuestion5.hpp"

using namespace std;

void mainQuestion5()
{
    vector<int> input;
	input = getVectorFromInput_Exo5("INP_CON_GRAPH.txt");
	
    int i;
	vector<vector<int>> output;

	output = matrixCompute(input);
	writeVectorIntotextFile_Exo5(output,"OUT_CON_GRAPH_MATRIX.txt");
    
	output = listCompute(input);
	writeVectorIntotextFile_Exo5(output,"OUT_CON_GRAPH_LIST.txt");
}