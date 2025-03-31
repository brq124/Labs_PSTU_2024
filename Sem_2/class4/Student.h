#pragma once
#include "Person.h"

class Student : public Person
{
protected:
	int m_study_year;
public:
	Student();
	Student(std::string, int, int);
	Student(const Student&);
	~Student();
	int getStudyYear();
	void setStudyYear(int);
	void IncreaseStudyYear();
	Student& operator=(const Student&);
	friend std::istream& operator>>(std::istream&, Student&);
	friend std::ostream& operator<<(std::ostream&, const Student&);
};

