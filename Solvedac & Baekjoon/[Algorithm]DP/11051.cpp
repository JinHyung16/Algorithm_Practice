#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ���� ��� 2 - DP �˰���
/// ���� ����� �־����� dp[i][j] = dp[i-1][j-1] + dp[i-1][j] ������ �̿��Ѵ�.
/// ���� ����� ��� (i,0) = 1�̰�, i==j �� ���� �׻� 1�̴�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int N = 0, K = 0; //�ڿ��� N�� ���� K
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