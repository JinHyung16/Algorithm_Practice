#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 나누기 - 브루트포스 알고리즘
/// N = N - N % 100을 한 이유는, N이 23442면 23400부터 시작하면 바로 나눠 떨어지기 때문이며
/// F가 최대 100이기에 N % 100한 값의 나머지를 뺀 값부터 시작하기 위함이다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	long long N = 0, F = 0; //N을 F로 나눈다.
	string result;

	std::cin >> N >> F;
	N = N - N % 100;
	while ( true )
	{
		if ( N % F == 0 )
		{
			break;
		}
		N++;
	}

	result = std::to_string(N);
	std::cout << result[result.size() - 2] << result[result.size() - 1] << "\n";
	return 0;
}