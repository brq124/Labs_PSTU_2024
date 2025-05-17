#include <iostream>
#include <vector>
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

	void DFS(const T& vert)
	{
		bool visited[MAXSIZE]{};
		DFSUtil(vert, visited);
	}
	void DFSUtil(const T& vert, bool* visited)
	{
		cout << vert << " ";
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
};

int main()
{
	setlocale(LC_ALL, "ru");
	Graph<int> graph;
	graph.InsertVert(2);
	graph.InsertVert(3);
	graph.InsertVert(4);
	graph.InsertEdgeDN(2, 3);
	graph.InsertEdgeDN(2, 4);
	graph.InsertEdgeDN(3, 4);
	graph.InsertVert(2);
	graph.Print();
	graph.DFS(2);
	return 0;
}
