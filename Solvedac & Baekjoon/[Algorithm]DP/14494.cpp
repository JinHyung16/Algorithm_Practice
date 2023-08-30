#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ���̳����� ������? - DP �˰���
/// dp[i][j]�� (1,1)���� (i,j)�� �����ϴ� ����� ��
/// dp[i][j] = dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1]�� �ϸ� �ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int n = 0, m = 0; //(1,1)���� (n,m)�� �����ϴ� ����� ��
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