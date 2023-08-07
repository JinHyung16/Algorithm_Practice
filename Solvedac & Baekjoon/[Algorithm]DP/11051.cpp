#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 이항 계수 2 - DP 알고리즘
/// 이항 계수가 주어지면 dp[i][j] = dp[i-1][j-1] + dp[i-1][j] 식으로 이용한다.
/// 이항 계수의 경우 (i,0) = 1이고, i==j 인 곳도 항상 1이다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int N = 0, K = 0; //자연수 N과 정수 K
	std::cin >> N >> K;
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	dp[0][0] = 1, dp[1][0] = 1, dp[1][1] = 1;

	for ( int i = 2; i <= N; i++ )
	{
		for ( int j = 0; j <= K; j++ )
		{
			if ( j == 0 || i == j )
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
			}
		}
	}

	std::cout << dp[N][K] << "\n";
	return 0;
}