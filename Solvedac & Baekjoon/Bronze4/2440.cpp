#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n(0);
	cin >> n;

	for (int row = 0; row < n; row++)
	{
		for (int i = 0; i < n - row; i++)
		{
			cout << "*";
		}

		for (int j = 0; j < row; j++)
		{
			cout << "";
		}

		cout << "\n";
	}
	return 0;
}