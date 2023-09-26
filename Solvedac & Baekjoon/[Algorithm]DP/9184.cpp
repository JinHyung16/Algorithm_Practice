#include<iostream>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 신나는 함수 실행 - DP 알고리즘
/// 문제에 주어진 W 함수를 이용해 해결한다.
/// </summary>
/// 
using namespace std;

int dp[21][21][21];

int Recursive(int a, int b, int c)
{
	if ( a <= 0 || b <= 0 || c <= 0 ) return 1;
	else if ( a > 20 || b > 20 || c > 20 )
		return Recursive(20, 20, 20);
	else if ( a < b && b < c )
	{
		if ( dp[a][b][c] != 0 ) return dp[a][b][c];
		else return dp[a][b][c] = Recursive(a, b, c - 1) + Recursive(a, b - 1, c - 1) - Recursive(a, b - 1, c);
	}
	else
	{
		if ( dp[a][b][c] != 0 ) return dp[a][b][c];
		else return dp[a][b][c] = Recursive(a - 1, b, c) + Recursive(a - 1, b - 1, c) + Recursive(a - 1, b, c - 1) - Recursive(a - 1, b - 1, c - 1);
	}
}

int main(void)
{
	FastIO;

	int a = 0, b = 0, c = 0;
	while ( true )
	{
		std::cin >> a >> b >> c;
		if ( a == -1 && b == -1 && c == -1 )
		{
			break;
		}
		std::cout << "w(" << a << ", " << b << ", " << c << ") = " << Recursive(a, b, c) << std::endl;

	}
	return 0;
}