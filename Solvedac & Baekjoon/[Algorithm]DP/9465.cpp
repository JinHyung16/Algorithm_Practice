#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ��ƼĿ - DP �˰���
/// 2���� �迭�� �����, ��ƼĿ���� ��ƼĿ ���� n�� ���� 2n���̹Ƿ� ���θ� 2ĭ���� �����Ѵ�.
/// �� �� �������� 0��° ������, 1��° �������� ���� ���� ����� dp�� �־����, �������� result = max(dp[0][n-1], dp[1][n-1])�� ���Ѵ�.
/// 1) �������� board[0][i]�ΰ�� -> dp[0][i] = board[0][i] + max(dp[1][i-1], dp[1][i-2]);
/// 2) �������� board[1][i]�ΰ�� -> dp[1][i] = board[1][i] + max(dp[0][i-1], dp[0][i-2]);
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int T = 0, n = 0; //�׽�Ʈ ���̽� ���� T, ��ƮĿ ���� n
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