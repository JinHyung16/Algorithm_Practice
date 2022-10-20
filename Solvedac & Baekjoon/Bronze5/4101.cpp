#include <iostream>

int ComparsionNum(const int& a, const int& b)
{
	if (a == 0 && b == 0)
	{
		return 0;
	}
	else
	{
		if (a > b)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
}

int main()
{
	int a(0), b(0);

	std::cin >> a >> b;

	while (ComparsionNum(a,b) != 0)
	{
		if (ComparsionNum(a, b) == 1)
		{
			std::cout << "Yes" << "\n";
		}
		else
		{
			std::cout << "No" << "\n";
		}

		std::cin >> a >> b;
	}
	return 0;
}