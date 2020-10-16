#include "Graph.h"

int main()
{
	Graph G(9);
	G.enter_vector_vertice();
	G.bfs(0);
	G.findDeWay(0, 4);
}