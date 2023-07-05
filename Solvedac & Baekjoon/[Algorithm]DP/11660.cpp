#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���� �� ���ϱ� 5 - DP �˰���
/// dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + board[i][j]; ���� ǥ���� �̸� �������� �����Ѵ�.
/// </summary>

using namespace std;

vector<vector<int>> board(10254, vector<int>(1025, 0));
vector<vector<int>> dp(1025, vector<int>(1025, 0));
int main(void)
{
	FastIO;

	int N = 0, M = 0; //N*N ũ�� ǥ�� ���� ���ؾ� �ϴ� Ƚ�� M
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