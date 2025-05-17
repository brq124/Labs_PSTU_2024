#include "Student.h"
#include <string>

Student::Student() : Person()
{
	m_study_year = 0;
}
Student::Student(std::string name, int age, int study_year) : Person(name, age)
{
	m_study_year = study_year;
}
Student::Student(const Student& s) : Person(s)
{
	m_study_year = s.m_study_year;
}
Student::~Student()
{

}
int Student::getStudyYear()
{
	return m_study_year;
}
void Student::setStudyYear(int study_year)
{
	if (study_year < 0)
	{
		study_year = 0;
		return;
	}
	m_study_year = study_year;
}
void Student::IncreaseStudyYear()
{
	m_study_year++;
}
Student& Student::operator=(const Student& s)
{
	m_name = s.m_name;
	m_age = s.m_age;
	m_study_year = s.m_study_year;
	return *this;
}
std::istream& operator>>(std::istream& is, Student& s)
{
	std::string name;
	std::cout << "Введите имя:" << std::endl;
	std::getline(is, name);
	s.setName(name);
	int age;
	std::cout << "Введите возраст:" << std::endl;
	is >> age;
	s.setAge(age);
	int study_year;
	std::cout << "Введите год обучения:" << std::endl;
	is >> study_year;
	s.setStudyYear(study_year);
	return is;
}
std::ostream& operator<<(std::ostream& os, const Student& s)
{
	os << "Студент " << &s << std::endl
		<< "Имя: " << s.m_name << std::endl
		<< "Возраст: " << s.m_age << std::endl
		<< "Год обучения: " << s.m_study_year;
	return os;
}

