#include <iostream>
using namespace std;

struct List
{
	struct Node
	{
		char data[100];
		Node* next_ptr = nullptr;
		void setData(const char* Data);
	};

	Node* head = nullptr, * tail = nullptr;

	void push_back(const char* Data);
	void push_front(const char* Data);
	void pop_back();
	void pop_front();

	Node* getAt(int pos);
	void insert(int pos, const char* Data);
	void erase(int pos);



	friend std::ostream& operator<<(std::ostream& os, List& list);
};

int main()
{
	setlocale(LC_ALL, "ru");
	List list;
	int N;
	cout << list;
	cout << "Введите количество элементов списка:" << endl;
	cin >> N;
	char s[100];
	for (int i = 1; i <= N; i++)
	{
		cout << "Введите " << i << " строку:" << endl;

		//cin.getline(s, 1);
		cin >> s;
		list.push_back(s);
	}
	cout << "Список: " << list << endl << endl;

	int K, n;
	cout << "Введите число K:" << endl;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cout << "бла бла бла " << endl;
		cin >> n;
		list.erase(n);
	}
	cout << "Список: " << list << endl;

	for (int i = 1; i <= K; i++)
	{
		cout << "Введите " << i << " строку:" << endl;

		//cin.getline(s, 1);
		cin >> s;
		list.push_front(s);
	}
	cout << "Список: " << list << endl;
	return 0;
}

void List::Node::setData(const char* Data)
{
	strcpy_s(data, Data);
};

void List::push_back(const char* Data) // da
{
	Node* temp = new Node;
	temp->setData(Data);
	if (head == nullptr) head = temp;
	if (tail != nullptr) tail->next_ptr = temp;
	tail = temp;
};

void List::push_front(const char* Data) // da
{
	Node* temp = new Node;
	temp->setData(Data);
	temp->next_ptr = head;
	head = temp;
	if (tail == nullptr) tail = temp;
};

void List::pop_back() // da
{
	if (head == nullptr) return;
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		return;
	}
	Node* temp = head;
	while (temp->next_ptr != tail)
	{
		temp = temp->next_ptr;
	}
	delete tail;
	tail = temp;
	tail->next_ptr = nullptr;
};

void List::pop_front() // da
{
	if (head == nullptr) return;
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		return;
	}
	Node* temp = head;
	head = head->next_ptr;
	delete temp;
}

List::Node* List::getAt(int pos) // da
{
	if (pos < 0 || head == nullptr) return nullptr;
	Node* temp = head;
	int i = 0;
	while (temp->next_ptr && i < pos)
	{
		temp = temp->next_ptr;
		i++;
	}
	if (i == pos) return temp;
	else return nullptr;
}

void List::insert(int pos, const char* Data) // 0 3 5 4
{
	Node* left = getAt(pos);
	if (left == nullptr) return;

	Node* right = left->next_ptr;
	Node* temp = new Node;
	temp->setData(Data);

	left->next_ptr = temp;
	temp->next_ptr = right;
}

void List::erase(int pos)
{
	if (pos < 0) return;
	if (pos == 0)
	{
		pop_front();
		return;
	}
	Node* left = getAt(pos - 1);
	Node* temp = left->next_ptr;
	if (temp == nullptr) return;

	Node* right = temp->next_ptr;
	left->next_ptr = right;
	if (temp == tail) tail = left;
	delete temp;

}

std::ostream& operator<<(std::ostream& os, List& list)
{
	if (list.head == nullptr) return os;
	List::Node* temp = list.head;
	while (temp->next_ptr)
	{
		os << temp->data << ' ';
		temp = temp->next_ptr;
	}
	os << temp->data;
	return os;
}
