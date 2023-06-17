#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 스티커 - DP 알고리즘
/// 2차원 배열을 만들고, 스티커판은 스티커 개수 n에 대해 2n개이므로 세로를 2칸으로 설정한다.
/// 그 후 시작점이 0번째 줄인지, 1번째 줄인지에 따라 최종 결과를 dp에 넣어놓고, 마지막에 result = max(dp[0][n-1], dp[1][n-1])로 구한다.
/// 1) 시작점이 board[0][i]인경우 -> dp[0][i] = board[0][i] + max(dp[1][i-1], dp[1][i-2]);
/// 2) 시작점이 board[1][i]인경우 -> dp[1][i] = board[1][i] + max(dp[0][i-1], dp[0][i-2]);
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int T = 0, n = 0; //테스트 케이스 개수 T, 스트커 개수 n
	vector<vector<int>> board(2, vector<int>(100001, 0));
	vector<vector<int>> dp(2, vector<int>(100001, 0));

	std::cin >> T;

	while ( T-- )
	{
		std::cin >> n;
		for ( int i = 0; i < n; i++ )
		{
			std::cin >> board[0][i];
		}
		for ( int i = 0; i < n; i++ )
		{
			std::cin >> board[1][i];
		}

		dp[0][0] = board[0][0];
		dp[1][0] = board[1][0];
		dp[0][1] = board[0][1] + dp[1][0];
		dp[1][1] = board[1][1] + dp[0][0];

		for ( int i = 2; i < n; i++ )
		{
			dp[0][i] = board[0][i] + std::max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = board[1][i] + std::max(dp[0][i - 1], dp[0][i - 2]);
		}

		int result = max(dp[0][n - 1], dp[1][n - 1]);
		std::cout << result << "\n";
	}
	return 0;
}