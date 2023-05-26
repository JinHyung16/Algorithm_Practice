#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 쉬운 계단 수 - Graph 알고리즘
/// 길이가 N인 계단 수의 의미를 파악해보자 (1 <= N <= 100 범위다)
/// N=1 -> 1~9까지 총 9개
/// N=2 -> 10 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98 총 17개
/// 
/// 즉 마지막 끝나는 수가 뭔지에 따라 앞에 오는 경우의 수들도 달라진다.
/// dp[i][j]는 i길이의 j로 끝나는 가짓수를 저장해둔다.
/// dp[2][2]는 2길이의 2로 끝나는 가짓수로 12와 32 총 2개다.
/// dp[2][2]는 dp[1][2] + dp[1][3]의 경우의 수를 합친 것이다.
/// 
/// 이때, 0으로 끝나는 수는 앞에 온 수가 나보다 1 커야하고, 9고 끝나는 수는 앞에 온 수가 나보다 1로 작아야하기에 따로 구한다.
/// dp[i][0] = dp[i-1][i+1]이고, dp[i][0] = dp[i-1][j-1]이다.
/// </summary>

using namespace std;

int mod = 1000000000;

int main(void)
{
	FastIO;

	int N(0); //계단수의 길이
	std::cin >> N;

	vector<vector<int>> dp(101, vector<int>(101, 0));
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][0] = dp[i - 1][j + 1];
			}
			else if (j == 9)
			{
				dp[i][9] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			dp[i][j] %= mod;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result = (result + dp[N][i]) % mod;
	}
	std::cout << result << "\n";
	return 0;
}
