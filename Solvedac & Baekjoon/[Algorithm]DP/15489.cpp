#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 파스칼 삼각형 - DP 알고리즘
/// dp[r][c] = dp[r-1][c-1] + dp[r-1][c]라는 점화식 이용
/// 미리 파스칼 삼각형을 범위만큼 만들고 그 다음 구해야하는 값을 구한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int R(0), C(0), W(0); //R번째 줄, C번째 수를 위 꼭짓점으로 하는 한 변이 포함하는 수의 개수 W인 정삼각형

	// 파스칼 삼각형 만들기
	vector<vector<int>> dp(32, vector<int>(32, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= 30; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	std::cin >> R >> C >> W;

	long long result = 0;

	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			result += dp[R - 1 + i][C - 1 + j];
		}
	}

	std::cout << result << "\n";
	return 0;
}