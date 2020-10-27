#include "Graph.h"

const int nH = 5;
const int highNumber = +INFINITY;

int main()
{
	//Init
	int graph[nH][nH];
	for (size_t j = 0; j < nH; j++)
	{
		for (size_t i = 0; i < nH; i++)
		{
			cin >> graph[j][i];
		}
	}

	//Algorithm Deixtra
	int start = 0;
	int finish = 4;
	int lenght;
	vector<vector<int>> visited(nH);
	visited[start][start] = 1;
	for (size_t i = 0; i < nH; i++)
	{
		for (size_t curent = 0; curent < nH; curent++)
		{
			if (!visited[i][curent])
			{
				visited[i][curent] = 1;
				if (graph[i][curent])
				{

				}
			}
		}
	}
}
