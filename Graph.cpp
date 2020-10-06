#include "Graph.h"

//Constructors/Destructors
Graph::Graph(size_t nmb)
{
	this->setNumberOfHeaders(nmb);
}

Graph::~Graph()
{

}


//Functions
void Graph::enterList()
{
	std::list<int> bufList;
	for (size_t j = 0; j < this->numberOfHeaders; j++)
	{
		std::cout << "\nEnter Headers for Head " << j << '\n';
		std::string str;
		std::getline(std::cin, str, '\n');
		for (unsigned i = 0; i < str.length(); ++i)
			if (str[i] != ' ')
				bufList.push_back(str[i] - '0');
		this->listOfNeighbors.push_back(bufList);
		bufList = {};
		str = {};
	}
}

void Graph::setNumberOfHeaders(size_t nmb)
{
	this->numberOfHeaders = nmb;
}

std::list<std::list<int>>& Graph::getList()
{
	return this->listOfNeighbors;
}

std::list<std::list<bool>>& Graph::getMatrix()
{
	return this->matrixOfAdjacencies;
}

std::stack<unsigned int> Graph::dFS()
{
	return std::stack<unsigned int>();
}

std::queue<unsigned int> Graph::bFS()
{
	std::queue<unsigned int> bFSQueue;
	for (auto i = this->listOfNeighbors.begin(); i != this->listOfNeighbors.end(); i++)
		for (auto j = i->begin(); j != i->end(); j++)
			bFSQueue.push(*j);
	return bFSQueue;
}

