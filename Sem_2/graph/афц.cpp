#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class T>
class Graph
{
private:
	static const int MAXSIZE = 20;
	std::vector<T> vertList;
	int adjMatrix[MAXSIZE][MAXSIZE];
public:
	Graph()
	{
		for (int i = 0; i < MAXSIZE; i++)
		{
			for (int j = 0; j < MAXSIZE; j++)
			{
				adjMatrix[i][j] = 0;
			}
		}
	}
	~Graph() {};

	int GetVertPos(const T& vertex)
	{
		for (int i = 0; i < vertList.size(); i++)
		{
			if (vertList[i] == vertex)
			{
				return i;
			}
		}
		return -1;
	}

	bool IsEmpty()
	{
		return vertList.empty();
	}
	bool IsFull()
	{
		return vertList.size() == MAXSIZE;
	}
	int GetAmountVerts()
	{
		return vertList.size();
	}
	int GetAmountEdgesD() // D - Directed
	{
		int amount = 0;
		int vertListSize = vertList.size();
		for (int i = 0; i < vertListSize; i++)
		{
			for (int j = 0; j < vertListSize; j++)
			{
				if (adjMatrix[i][j] != 0)
				{
					amount++;
				}
			}
		}
		return amount;
	}
	int GetAmountEdgesU() // U - Undirected
	{
		int amount = 0;
		int vertListSize = vertList.size();
		for (int i = 0; i < vertListSize; i++)
		{
			for (int j = 0; j < vertListSize; j++)
			{
				if (adjMatrix[i][j] != 0)
				{
					amount++;
				}
			}
		}
		return amount / 2;
	}
	int GetWeight(const T& vert1, const T& vert2)
	{
		if (vertList.empty()) return 0;

		int vertpos1 = GetVertPos(vert1);
		int vertpos2 = GetVertPos(vert2);
		return adjMatrix[vertpos1][vertpos2];
	}

	std::vector<T> GetNbours(const T& vert)
	{
		std::vector<T> nboursList;
		int vertpos = GetVertPos(vert);
		if (vertpos == -1) return nboursList;
		for (int i = 0; i < vertList.size(); i++)
		{
			if (adjMatrix[vertpos][i] != 0)
			{
				nboursList.push_back(vertList[i]);
			}
		}
		return nboursList;
	}
	void InsertVert(const T& vert)
	{
		if (this->IsFull())
		{
			cout << "Граф заполнен." << endl;
			return;
		}
		if (this->GetVertPos(vert) != -1)
		{
			cout << "Вершина " << vert << " уже есть." << endl;
			return;
		}
		vertList.push_back(vert);
	}
	void InsertEdgeUN(const T& vert1, const T& vert2) // UN - Undirected Unweighted
	{
		int vertpos1 = GetVertPos(vert1);
		int vertpos2 = GetVertPos(vert2);
		if (vertpos1 == -1 || vertpos2 == -1)
		{
			cout << "Вершин нема." << endl;
			return;
		}
		if (adjMatrix[vertpos1][vertpos2] != 0)
		{
			cout << "Ребро между этими вершинами уже есть." << endl;
			return;
		}
		adjMatrix[vertpos1][vertpos2] = 1;
		adjMatrix[vertpos2][vertpos1] = 1;
	}
	void InsertEdgeUW(const T& vert1, const T& vert2, const int& weight) // UW - Undirected Weighted
	{
		int vertpos1 = GetVertPos(vert1);
		int vertpos2 = GetVertPos(vert2);
		if (vertpos1 == -1 || vertpos2 == -1)
		{
			cout << "Вершин нема." << endl;
			return;
		}
		if (adjMatrix[vertpos1][vertpos2] != 0)
		{
			cout << "Ребро между этими вершинами уже есть." << endl;
			return;
		}
		adjMatrix[vertpos1][vertpos2] = weight;
		adjMatrix[vertpos2][vertpos1] = weight;
	}
	void InsertEdgeDN(const T& vert1, const T& vert2) // DN - Directed Unweighted
	{
		int vertpos1 = GetVertPos(vert1);
		int vertpos2 = GetVertPos(vert2);
		if (vertpos1 == -1 || vertpos2 == -1)
		{
			cout << "Вершин нема." << endl;
			return;
		}
		if (adjMatrix[vertpos1][vertpos2] != 0)
		{
			cout << "Ребро между этими вершинами уже есть." << endl;
			return;
		}
		adjMatrix[vertpos1][vertpos2] = 1;
	}
	void InsertEdgeDW(const T& vert1, const T& vert2, const int& weight) // DW - Directed Weighted
	{
		int vertpos1 = GetVertPos(vert1);
		int vertpos2 = GetVertPos(vert2);
		if (vertpos1 == -1 || vertpos2 == -1)
		{
			cout << "Вершин нема." << endl;
			return;
		}
		if (adjMatrix[vertpos1][vertpos2] != 0)
		{
			cout << "Ребро между этими вершинами уже есть." << endl;
			return;
		}
		adjMatrix[vertpos1][vertpos2] = weight;
	}
	void Print()
	{
		if (vertList.empty())
		{
			std::cout << "Граф пуст." << endl;
			return;
		}
		int vertListSize = vertList.size();
		std::cout << "Таблица смещения для графа:" << std::endl << "   ";
		for (int i = 0; i < vertListSize; i++)
		{
			cout << vertList[i] << "  ";
		}
		cout << endl;
		for (int i = 0; i < vertListSize; i++)
		{
			cout << vertList[i] << "  ";
			for (int j = 0; j < vertListSize; j++)
			{
				std::cout << adjMatrix[i][j] << "  ";
			}
			std::cout << std::endl;
		}
	}

	void DFS(const T& vert) // Обход в глубину
	{
		bool visited[MAXSIZE]{};
		DFSUtil(vert, visited);
	}
	void DFSUtil(const T& vert, bool* visited)
	{
		cout << "Вершина " << vert << " обработана.";
		int vertpos = GetVertPos(vert);
		visited[vertpos] = true;
		vector<T> nboursList = GetNbours(vert);
		for (int i = 0; i < nboursList.size(); i++)
		{
			int nbourvertpos = GetVertPos(nboursList[i]);
			if (!visited[nbourvertpos])
			{
				DFSUtil(nboursList[i], visited);
			}
		}
	}
	void BFS(const T& vert) // Обход в глубину
	{
		bool visited[MAXSIZE]{};
		BFSUtil(vert, visited);
	}
	void BFSUtil(const T& vert, bool* visited)
	{
		queue<T> q;
		q.push(vert);
		int vertpos = GetVertPos(vert);
		visited[vertpos] = true;
		cout << "Вершина " << vert << " обработана.";
		while (!q.empty())
		{
			T vert = q.front();
			q.pop();
			vector<T> nboursList = GetNbours(vert);
			for (const T& nbourvert : nboursList)
			{
				T nbourpos = GetVertPos(nbourvert);
				if (visited[nbourpos]) continue;
				q.push(nbourvert);
				visited[nbourpos] = true;
				cout << "Вершина " << nbourvert << " обработана.";
			}
		}
	}

	void ReduceMatrix()
	{

	}


};

int main()
{
	setlocale(LC_ALL, "ru");
	Graph<int> graph;
	graph.InsertVert(1);
	graph.InsertVert(2);
	graph.InsertVert(3);
	graph.InsertVert(4);
	graph.InsertVert(5);
	graph.InsertVert(6);
	graph.InsertEdgeDW(1, 3, 13);
	graph.InsertEdgeDW(1, 4, 15);
	graph.InsertEdgeDW(2, 1, 28);
	graph.InsertEdgeDW(2, 4, 20);
	graph.InsertEdgeDW(3, 5, 30);
	graph.InsertEdgeDW(4, 6, 31);
	graph.InsertEdgeUW(4, 5, 39);
	graph.InsertEdgeDW(5, 2, 21);
	graph.InsertEdgeDW(6, 1, 18);
	//graph.Print();
	graph.DFS(5);
	graph.BFS(5);
	return 0;
}
