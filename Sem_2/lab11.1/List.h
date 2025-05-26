#pragma once
#include <ostream>
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

