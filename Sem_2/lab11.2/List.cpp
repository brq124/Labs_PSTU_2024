#include "List.h"

void List::Node::setData(const char* Data)
{
	strcpy_s(data, Data);
};

void List::push_back(const char* Data) // da
{
	Node* temp = new Node;
	temp->setData(Data);
	temp->prev_ptr = tail;
	if (head == nullptr) head = temp;
	if (tail != nullptr) tail->next_ptr = temp;
	tail = temp;
};

void List::push_front(const char* Data) // da
{
	Node* temp = new Node;
	temp->setData(Data);
	temp->next_ptr = head;
	if(head != nullptr) head->prev_ptr = temp;
	head = temp;
	if (tail == nullptr) tail = temp;
};

void List::pop_back() // da 5 2 8 [2]
{
	if (head == nullptr) return;
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		return;
	}
	Node* temp = tail;
	tail = temp->prev_ptr;
	delete temp;
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

void List::erase(int pos) // yes
{
	if (pos < 0) return;
	if (pos == 0)
	{
		pop_front();
		return;
	}
	Node* temp = getAt(pos);
	if (temp == nullptr) return;
	Node* left = temp->prev_ptr;
	Node* right = temp->next_ptr;
	left->next_ptr = right;
	if (right != nullptr) right->prev_ptr = left;
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

