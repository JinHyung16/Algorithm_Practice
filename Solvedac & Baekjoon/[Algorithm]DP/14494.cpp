#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 다이나믹이 뭐예요? - DP 알고리즘
/// dp[i][j]는 (1,1)에서 (i,j)에 도달하는 경우의 수
/// dp[i][j] = dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1]을 하면 된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int n = 0, m = 0; //(1,1)에서 (n,m)에 도달하는 경우의 수
	std::cin >> n >> m;

	int mod = 1000000007;
	vector<vector<long long>> dp(1010, vector<long long>(1010, 0));
	dp[1][1] = 1;
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			if ( i * j != 1 )
			{
				dp[i][j] = (dp[i][j - 1] % mod + dp[i - 1][j] % mod + dp[i - 1][j - 1] % mod) % mod;
			}
		}
	}

	std::cout << dp[n][m] % mod << "\n";
	return 0;
}