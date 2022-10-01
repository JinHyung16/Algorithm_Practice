#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a(0), b(0), c(0);

	cin >> a >> b >> c;
	if ((a == b) && (b == c))
	{
		cout << 10000 + (a * 1000) << "\n";
	}
	else
	{
		if (a == b)
		{
			cout << 1000 + (a * 100) << "\n";
		}
		else if (b == c)
		{
			cout << 1000 + (b * 100) << "\n";
		}
		else if (a == c)
		{
			cout << 1000 + (c * 100) << "\n";
		}
		else
		{
			if (a > b && a > c)
			{
				cout << 100 * a << "\n";
			}
			else if (b > c && b > a)
			{
				cout << 100 * b << "\n";
			}
			else if (c > b && c > a)
			{
				cout << 100 * c << "\n";
			}
		}
	}
	return 0;
}