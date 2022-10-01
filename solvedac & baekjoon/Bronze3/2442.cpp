#include<iostream>
using namespace std;

int main()
{
	int n(0);

	cin >> n;

	for (int row = 0; row < n; row++)
	{
		for (int j = row; j < n - 1; j++)
		{
			cout << " ";
		}
		for (int i = 0; i < (2 * row + 1); i++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}