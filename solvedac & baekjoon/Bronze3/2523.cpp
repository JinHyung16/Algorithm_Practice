#include<iostream>
using namespace std;

int main()
{
	int n(0);

	cin >> n;
	// 위쪽
	for (int row = 0; row < n; row++)
	{
		for (int i = 0; i < row + 1; i++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	// 아래쪽
	for (int row = 0; row < n - 1; row++)
	{
		for (int i = 0; i < n - 1 - row; i++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}