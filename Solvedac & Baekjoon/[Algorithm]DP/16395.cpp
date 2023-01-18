#include<iostream>
#include<vector>

/// <summary>
/// Silver5 파스칼의 삼각형 - DP 알고리즘
/// dp[i][j] = dp[i-1][j-1] + dp[i-1][j]다.
/// 이는 본인 왼쪽 위 + 왼쪽 수의 합으로 파스칼 정의 따른다.
/// 시작시 양 끝은 1이라고 했으므로 각 행의 첫 번째 수를 1로 초기화 해둔다
/// 이때 k <= n <= 30이므로 최초 실행시 30번까지 돌려봐야한다.
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0), K(0); //n번째 행 k번째 수

	vector<vector<int>> dp(31, vector<int>(31, 0));
	std::cin >> N >> K;

	for (int i = 0; i < 31; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 0; i < 31; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	std::cout << dp[N - 1][K - 1] << std::endl;
	return 0;
}