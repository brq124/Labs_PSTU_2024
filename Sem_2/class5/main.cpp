#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	Student s;
	Person* p = &s;
	cout << s << endl;
	cout << *p << endl;
	cin >> s;
	//cin >> p;
	cout << s << endl;
}
