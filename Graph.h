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
	//rectangle
	Graph(size_t, size_t);
	virtual ~Graph();

	void enter_vector_vertice();
	void vectorToMatrix();
	void showMatrix();
	void bfs(int);
	void findDeWay(int, int);

private:
	vector<vector<int>> vertice;	//vector of vertice
	int nVertice = 0;	//number of vertice
	vector<vector<bool>> adjacency;
	int width = 0, height = 0;
};
