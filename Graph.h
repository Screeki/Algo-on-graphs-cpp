#pragma once
#include <iostream>
#include "string"
#include <list>
#include <iterator>
#include <locale> 
#include <stack>
#include <queue>
using namespace std;

class Graph
{
public:
	//Constructors/Destructors
	Graph(size_t);
	virtual ~Graph();

	void enter_vector_vertice();
	void vectorToMatrix();
	void showMatrix();
	void bfs(int start);

private:
	vector<vector<int>> vertice;	//vector of vertice
	int nVertice;	//number of vertice
	vector<vector<bool>> adjacency;
};
