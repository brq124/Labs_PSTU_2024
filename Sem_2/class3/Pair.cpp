#include "Pair.h"
#include <iostream>

Pair::Pair()
{
	m_first = 0;
	m_second = 0;
}
Pair::Pair(int first, double second)
{
	m_first = first;
	m_second = second;
}
Pair::Pair(const Pair& p)
{
	m_first = p.m_first;
	m_second = p.m_second;
}
Pair::~Pair()
{

}
int Pair::getFirst()
{
	return m_first;
}
void Pair::setFirst(int first)
{
	m_first = first;
}
double Pair::getSecond()
{
	return m_second;
}
void Pair::setSecond(double second)
{
	m_second = second;
}
bool operator<(Pair& p1, Pair& p2)
{
	return (p1.m_first + p1.m_second) < (p2.m_first + p2.m_second);
}
bool operator>(Pair& p1, Pair& p2)
{
	return (p1.m_first + p1.m_second) > (p2.m_first + p2.m_second);
}
Pair& Pair::operator++()
{
	m_first++;
	return *this;
}
Pair& Pair::operator++(int)
{
	m_second++;
	return *this;
}
Pair& Pair::operator=(const Pair& p)
{
	m_first = p.m_first;
	m_second = p.m_second;
	return *this;
}
std::istream& operator>>(std::istream& is, Pair& p)
{
	int first;
	std::cin >> first;
	p.setFirst(first);
	double second;
	std::cin >> second;
	p.setSecond(second);
	return is;
}
std::ostream& operator<<(std::ostream& os, const Pair& p)
{
	os << '(' << p.m_first << ", " << p.m_second << ')';
	return os;
}

