#include <iostream>
using namespace std;

int main()
{
	int n, tmp;
	bool plusFirst = false;
	bool minusFirst = false;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (!plusFirst && !minusFirst)
		{
			if (tmp > 0) plusFirst = true;
			else if (tmp < 0) minusFirst = true;
		}
	}
	if (plusFirst) cout << "������� ����� ������������� �����";
	else if (minusFirst) cout << "������� ����� ������������� �����";
	else cout << "��� �������� ���� ��������";
	return 0;
}

