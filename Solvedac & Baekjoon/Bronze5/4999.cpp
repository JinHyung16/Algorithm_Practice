#include<iostream>
#include<string>
int main()
{
	std::string a, b;
	std::cin >> a >> b;

	if (a.length() >= b.length())
	{
		std::cout << "go" << "\n";
	}
	else
	{
		std::cout << "no" << "\n";
	}
	return 0;
}