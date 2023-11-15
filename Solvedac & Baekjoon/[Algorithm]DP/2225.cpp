#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold5 합분해 - DP 알고리즘
/// 이를 2차원 배열로 바꾸면 dp[n][k]로 0부터 n까지 정수 k개를 더해 합이 N이 되는 경우의 수
/// dp[i][k] = dp[i-1][k] + dp[i][k-1]이다.
/// 초기 dp[1][k]는 for i <= K dp[1][k] = i다.
/// 왜냐면 0으로 1은 9가지 1로 1은 1가지 2로 2는 0가지이기 때문
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0, K = 0; //0부터 N까지의 정수 K개를 더해 그 합이 N이 되는 경우의 수
	cin >> N >> K;
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

	for (int i = 0; i <= K; i++)
	{
		dp[1][i] = i; // 1을 만드는 k개의 수는 모두 i가지다. (왜냐면 0으로 1은 9가지 1로 1은 1가지 2로 2는 0가지이기 때문)
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}

	cout << dp[N][K] << "\n";
	return 0;
}