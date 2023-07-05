#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 구간 합 구하기 5 - DP 알고리즘
/// dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + board[i][j]; 통해 표위의 미리 누적합을 저장한다.
/// </summary>

using namespace std;

vector<vector<int>> board(10254, vector<int>(1025, 0));
vector<vector<int>> dp(1025, vector<int>(1025, 0));
int main(void)
{
	FastIO;

	int N = 0, M = 0; //N*N 크기 표와 합을 구해야 하는 횟수 M
	std::cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			std::cin >> board[i][j];
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + board[i][j];
		}
	}

	int stackSum = 0;
	for(int i = 0; i < M; i++)
	{
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		std::cin >> x1 >> y1 >> x2 >> y2;
		stackSum = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
		std::cout << stackSum << "\n";
	}
	return 0;
}