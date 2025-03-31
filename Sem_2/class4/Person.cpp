#include "Person.h"
#include <string>

Person::Person()
{
	m_name = "null";
	m_age = 0;
}
Person::Person(std::string name, int age)
{
	m_name = name;
	m_age = age;
}
Person::Person(const Person& p)
{
	m_name = p.m_name;
	m_age = p.m_age;
}
Person::~Person()
{

}
std::string Person::getName()
{
	return m_name;
}
void Person::setName(std::string name)
{
	m_name = name;
}
int Person::getAge()
{
	return m_age;
}
void Person::setAge(int age)
{
	m_age = age;
}
Person& Person::operator=(const Person& p)
{
	m_name = p.m_name;
	m_age = p.m_age;
	return *this;
}
std::istream& operator>>(std::istream& is, Person& p)
{
	std::string name;
	std::cout << "Введите имя:" << std::endl;
	std::getline(is, name);
	p.setName(name);
	int age;
	std::cout << "Введите возраст:" << std::endl;
	is >> age;
	p.setAge(age);
	return is;
}
std::ostream& operator<<(std::ostream& os, const Person& p)
{
	os << "Человек " << &p << std::endl
		<< "Имя: " << p.m_name << std::endl
		<< "Возраст: " << p.m_age;
	return os;
}

