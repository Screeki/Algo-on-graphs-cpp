#include "Graph.h"

Graph::Graph(size_t arg = 0)
{
	this->nVertice = arg;
}

Graph::Graph(size_t w, size_t h)
{
	this->width = w;
	this->height = h;
}

Graph::~Graph()
{
}

void Graph::enter_vector_vertice()
{
	string bufString;
	vector<int> bufVector;
	for (size_t curentVertice = 0; curentVertice < nVertice; curentVertice++)
	{
		cout << "\nEnter connected vertices for " << curentVertice << " vertice: ";
		getline(cin, bufString);
		for (unsigned i = 0; i < bufString.length(); ++i)
			if (bufString[i] != ' ')
				bufVector.push_back(bufString[i] - '0');
		this->vertice.push_back(bufVector);
		bufVector = {};
	}

}

void Graph::vectorToMatrix()
{
	std::vector<bool> bufList;
	for (auto i = this->vertice.begin(); i != this->vertice.end(); i++)
	{
		auto it = i->begin();
		for (size_t j = 0; j < this->vertice.size(); j++)
		{
			if (!i->empty() && it != i->end())
				if (j == *it) { bufList.push_back(1); it++; continue; }
			bufList.push_back(0);
		}
		this->adjacency.push_back(bufList);
		bufList = {};
	}
}
void Graph::showMatrix()
{
	for (auto x = this->adjacency.begin(); x != this->adjacency.end(); x++)
	{
		auto it = x->begin();
		for (size_t i = 0; i < this->adjacency.size(); i++)
		{
			cout << *it;
			it++;
		}
		cout << endl;
	}
}

void Graph::bfs(int start = 0)
{
	queue<int> q;
	vector<int> visited(this->nVertice);
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int v = q.front();
		cout << v;
		q.pop();
		for (size_t i = 0; i < this->vertice[v].size(); i++)
		{
			if (!visited[this->vertice[v][i]])
			{
				visited[this->vertice[v][i]] = true;
				q.push(this->vertice[v][i]);
			}
		}
	}
}

void Graph::findDeWay(int start, int end)
{
	queue<int> q;
	vector<int> visited(this->nVertice);
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int v = q.front();
		cout << "\n Checked: " << v;
		q.pop();
		for (size_t i = 0; i < this->vertice[v].size(); i++)
		{
			if (!visited[this->vertice[v][i]])
			{
				visited[this->vertice[v][i]] = true;
				q.push(this->vertice[v][i]);
				if (this->vertice[v][i] == end)
				{
					cout << "\n I know de way.";
					return;
				}
			}
		}
	}

}
