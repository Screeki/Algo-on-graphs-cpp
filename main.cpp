#include "Graph.h"

int main()
{
	Graph G(4);
	G.enterList();
	std::queue<unsigned int> bFSQueue = G.bFS();
	size_t sz = bFSQueue.size();
	for (size_t i = 0; i < sz; i++)
	{
		std::cout << bFSQueue.front() << ' ';
		bFSQueue.pop();
	}
}

// 0:3		1:		2:3		3:0,2