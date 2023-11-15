#include "./mainQuestion6.hpp"

void mainQuestion6()
{
	std::cout << "test" << std::endl;
	std::vector<int> input;
	input = getVectorFromInput_Exo6("INP_DIJ_GRAPH.txt");

	std::cout << "Vecteur d'entree :" << std::endl;
	
	for (int test : input)
	{
		std::cout << test << " ";
	}
	std::cout << std::endl;


	int i;
	std::vector<int> output;
	output = matrixCompute(input);
	/*writeVectorIntotextFile_Exo6(output, "OUT_DIJ_GRAPH_MATRIX.txt");*/
}
