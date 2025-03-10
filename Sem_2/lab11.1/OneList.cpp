#include <iostream>
using namespace std;

struct List
{
	struct Node
	{
		char* data;
		Node* next_ptr = nullptr;
		void setData(char* Data);
	};

	Node* head = nullptr, * tail = nullptr;

	void push_back(char* Data);
	void push_front(char* Data);
	void pop_back();
	void pop_front();

	void getAt();
	void insert();
	void erase();

	friend std::ostream& operator<<(std::ostream& os, List& list);
};

int main()
{
	setlocale(LC_ALL, "ru");
	List list;
	int N;
	cout << "Введите количество элементов списка:" << endl;
	cin >> N;
	char* elem = new char[N];
	cout << end(elem);
	for (int i = 1; i <= N; i++)
	{
		cout << "Введите " << i << "строку:" << endl;

		cin.getline(elem, N, '**');
		list.push_back(elem);
	}
	cout << list;
	return 0;
}

void List::Node::setData(char* Data)
{
	data = Data;
};

void List::push_back(char* Data)
{
	Node* temp = new Node;
	temp->setData(Data);
	if (head == nullptr)
	{
		head = tail = temp;
		return;
	}
	tail->next_ptr = temp;
	tail = temp;
};

void List::push_front(char* Data)
{
	Node* temp = new Node;
	temp->setData(Data);
	if (head == nullptr)
	{
		head = tail = temp;
		return;
	}
	temp->next_ptr = head;
	head = temp;
};

void List::pop_back()
{

};

void List::pop_front()
{
	Node* temp = head;
	head = head->next_ptr;
	delete temp;
}

std::ostream& operator<<(std::ostream& os, List& list)
{
	if (list.head == nullptr) return;
	List::Node* temp = list.head;
	while (temp->next_ptr)
	{
		std::os << temp->data[0] << ' ';
		temp = temp->next_ptr;
	}
	std::os << temp->data << ' ';
	return os;
}
