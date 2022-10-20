#include<iostream>

using namespace std;

// Recursive시 time out 해결 방법 -> 이전 값들을 저장해놓고 쓰자

int main(void)
{
	int n = 0;
	long long fibonacci_list[91] = { 0, };

	cin >> n;

	fibonacci_list[0] = 0;
	fibonacci_list[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		fibonacci_list[i] = fibonacci_list[i - 1] + fibonacci_list[i - 2];
	}

	cout << fibonacci_list[n];

	return 0;
}