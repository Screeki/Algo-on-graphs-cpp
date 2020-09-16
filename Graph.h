#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <iterator>
#include <locale> 

class Graph
{
public:
	//Constructors/Destructors
	Graph();
	virtual ~Graph();

	//Functions
	//Writing to list of lists of integer
	void enterList(std::list<std::list<int>>&);

	//Template Functions
	template<class T>
	void setList(T&);
	template<class From, class To>
	void convert(From&, To&);
	template<class T>
	void show(T& data);

private:
	//List/Matrix
	std::list<std::list<int>> listOfNeighbors;
	std::list<std::list<bool>> matrixOfAdjacencies;

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