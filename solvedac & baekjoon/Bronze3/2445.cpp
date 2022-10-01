#include<iostream>
using namespace std;

int main()
{
	int n(0);

	cin >> n;
	// 嬪薹
	for (int row = 0; row < n; row++)
	{
		// 謝難
		for (int i = 0; i < row + 1; i++)
		{
			cout << "*";
		}
		for (int j = 0; j < n - (row + 1); j++)
		{
			cout << " ";
		}

		// 辦難
		for (int j = 0; j < n - (row + 1); j++)
		{
			cout << " ";
		}
		for (int i = 0; i < row + 1; i++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	// 嬴楚薹
	for (int row = 0; row < n; row++)
	{
		// 謝難
		for (int i = 0; i < n - (row + 1); i++)
		{
			cout << "*";
		}
		for (int j = 0; j < row + 1; j++)
		{
			cout << " ";
		}
		// 辦難
		for (int j = 0; j < row + 1; j++)
		{
			cout << " ";
		}
		for (int i = 0; i < n - (row + 1); i++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}