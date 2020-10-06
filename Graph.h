#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "string"
#include <list>
#include <iterator>
#include <locale> 
#include <stack>
#include <queue>

class Graph
{
public:
	//Constructors/Destructors
	Graph(size_t);
	virtual ~Graph();

	//Functions
	//Writing to list of lists of integer
	void enterList();
	void setNumberOfHeaders(size_t);
	std::list<std::list<int>>& getList();
	std::list<std::list<bool>>& getMatrix();
	//Deep/Breadth search in List Realization
	std::stack<unsigned int> dFS();
	std::queue<unsigned int> bFS();

	//Template Functions
	template<class T>
	void setList(T&);
	template<class From, class To>
	void convert(From&, To&);
	template<class T>
	void show(T&);

private:
	//List/Matrix
	std::list<std::list<int>> listOfNeighbors;
	std::list<std::list<bool>> matrixOfAdjacencies;
	size_t numberOfHeaders;

};

//Template Functions
template<class T>
inline void Graph::setList(T& data)
{
	try
	{
		this->listOfNeighbors = data;
		if (0)
			throw (-1);
	}
	catch (int x)
	{
		std::cout << "'\n'Wrong type - Error " << x;
	}
}

template<class From, class To>
inline void Graph::convert(From& from, To& to)
{
	std::list<bool> bufList;
	for (auto i = from.begin(); i != from.end(); i++)
	{
		auto it = i->begin();
		for (size_t j = 0; j < from.size(); j++)
		{
			if (!i->empty() && it!=i->end())
				if (j == *it) { bufList.push_back(1); it++; continue; }
			bufList.push_back(0);
		}
		to.push_back(bufList);
		bufList = {};
	}
}

template<class T>
inline void Graph::show(T& data)
{
	for (auto x = data.begin(); x != data.end(); x++)
	{
		auto it = x->begin();
		for (size_t i = 0; i < data.size(); i++)
		{
			std::cout << *it;
			it++;
		}
		std::cout << std::endl;
	}
}

#endif