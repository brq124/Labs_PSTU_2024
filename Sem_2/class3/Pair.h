#pragma once
#include <iostream>

class Pair
{
private:
	int m_first;
	double m_second;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	int getFirst();
	void setFirst(int);
	double getSecond();
	void setSecond(double);
	friend bool operator<(Pair&, Pair&);
	friend bool operator>(Pair&, Pair&);
	Pair& operator++();
	Pair& operator++(int);
	Pair& operator=(const Pair&);
	friend std::istream& operator>>(std::istream&, Pair&);
	friend std::ostream& operator<<(std::ostream&, const Pair&);
};

