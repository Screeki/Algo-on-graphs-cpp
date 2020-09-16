#include "Graph.h"

int main()
{
	Graph G;

	std::list<std::list<int>> list;
	G.enterList(list);
	G.setList(list);

	std::list<std::list<bool>> matrix;
	G.convert(list, matrix);
	G.show(matrix);

	std::cin.get();
	std::cin.get();
}

// 0:3		1:		2:3		3:0,2