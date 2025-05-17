#pragma once
#include <iostream>

class Person
{
protected:
	std::string m_name;
	int m_age;
public:
	Person();
	Person(std::string, int);
	Person(const Person&);
	~Person();
	std::string getName();
	void setName(std::string);
	int getAge();
	void setAge(int);
	Person& operator=(const Person&);
	friend std::istream& operator>>(std::istream&, Person&);
	friend std::ostream& operator<<(std::ostream&, const Person&);
};

