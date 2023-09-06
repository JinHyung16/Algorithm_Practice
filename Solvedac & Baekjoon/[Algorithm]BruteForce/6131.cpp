#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 완전 제곱수 - 브루트포스 알고리즘
/// 문제에 주어진 조건처럼, 최대 범위인 500까지 2중 for문을 돌면서
/// a*a = b*b + N을 이용한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0;
	std::cin >> N;

	int result = 0;
	for ( int i = 1; i <= 500; i++ )
	{
		for ( int j = i + 1; j <= 500; j++ )
		{
			if ( j * j == i * i + N )
			{
				result++;
			}
		}
	}

	std::cout << result << "\n";
	return 0;
}