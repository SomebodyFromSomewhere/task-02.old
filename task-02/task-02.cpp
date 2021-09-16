#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <time.h>
#include <vector>
#include "utils/utils.h"

struct graph {
	bool visited, is_empty;
};



void getLinesAndColumns(std::ifstream& inpt_file, int& lines, int& columns) {
	std::string str;
	std::getline(inpt_file, str);
	std::vector<int> tmp = splitInt(str, ' ');
	lines = tmp[0];
	columns = tmp[1];
}

std::vector<std::vector<graph>> getGraph(std::ifstream& file, int lines, int colomns) {
	std::vector<std::vector<graph>> graph_array(lines, std::vector <graph> (colomns));
	std::string str;
	std::vector<std::string> tmp;
	graph vertex;
	for (int i = 0; i < lines; i++)
	{
		std::getline(file, str);
		tmp = splitString(str, ' ');
		for (int j = 0; j < tmp[0].size(); j++)
		{
			if (tmp[0][j] == '.')
			{
				vertex.is_empty = true;
			}
			else
			{
				vertex.is_empty = false;
			}
			vertex.visited = false;
			graph_array[i][j] = vertex;
		}
	}
	return graph_array;

}

void readFromFile(std::string file_name, std::vector<std::vector<graph>>& graph_array) {
	std::ifstream file(file_name);
	int lines, columns;
	getLinesAndColumns(file, lines, columns);
	graph_array = getGraph(file, lines, columns);
}

int main()
{
	clock_t start = clock();
	std::vector<std::vector<graph>> graph_array;
	readFromFile("INPUT.txt", graph_array);

	executionTime(start, "MAIN");
	return 0;
}