#include<iostream>

using namespace std;

// Divide-and-Conquer
long long Fibonacci(int n)
{
	if (n == 0)
	{
		return n;

	}
	if (n == 1)
	{
		return n;
	}
	
	return (Fibonacci(n - 1) + Fibonacci(n - 2));
}

int main(void)
{
	int n = 0;
	cin >> n;

	int index = 0;
	long long finbonacci_number = 0;
	while (index <= n)
	{
		finbonacci_number = Fibonacci(index);
		index++;
	}

	cout << finbonacci_number;

	return 0;
}