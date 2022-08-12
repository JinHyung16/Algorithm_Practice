#include<iostream>
using namespace std;

int main()
{
	int n(0);

	cin >> n;

	for (int row = 0; row < n; row++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << " ";
		}
		for (int i = row; i < (2 * n - 1 - row); i++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}