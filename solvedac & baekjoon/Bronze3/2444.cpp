#include<iostream>
using namespace std;

int main()
{
	int n(0);

	cin >> n;

	// 0 ~ n/2 ���Ա��� row ������ ���� �� ����
	for (int row = 0; row < n; row++)
	{
		for (int j = 0; j < n - (row + 1); j++)
		{
			cout << " ";
		}
		for (int i = 0; i < 2 * row + 1; i++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	// n/2 �ʰ� n���� row ������ ���� �� ����
	for (int row = 0; row < n - 1; row++)
	{
		for (int j = 0; j < row + 1; j++)
		{
			cout << " ";
		}
		for (int i = 0; i < 2 * (n - 1) - (2 * row + 1); i++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}