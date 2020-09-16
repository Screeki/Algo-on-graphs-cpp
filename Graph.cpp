#include "Graph.h"

//Constructors/Destructors
Graph::Graph()
{

}

Graph::~Graph()
{

}

//Functions
void Graph::enterList(std::list<std::list<int>>& list)
{
	std::list<int> bufList;
	int mainHead = 0;
	size_t kostil, kostil2;

	std::cout << "\nHow much Headers we have? ";
	std::cin >> kostil2;

	for (size_t j = 0; j < kostil2; j++)
	{
		std::cout << "\nHow much headers we have for Head " <<
			mainHead << std::endl;
		std::cin >> kostil;

		std::cout << "\nEnter(lower to rise) header for " <<
			mainHead << std::endl;
		for (size_t i = 0; i < kostil; i++)
		{
			int head;
			std::cin >> head;
			bufList.push_back(head);
		}
		list.push_back(bufList);
		bufList = {};
		mainHead++;
	}
}

