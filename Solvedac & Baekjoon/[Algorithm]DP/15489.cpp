#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 �Ľ�Į �ﰢ�� - DP �˰���
/// dp[r][c] = dp[r-1][c-1] + dp[r-1][c]��� ��ȭ�� �̿�
/// �̸� �Ľ�Į �ﰢ���� ������ŭ ����� �� ���� ���ؾ��ϴ� ���� ���Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int R(0), C(0), W(0); //R��° ��, C��° ���� �� ���������� �ϴ� �� ���� �����ϴ� ���� ���� W�� ���ﰢ��

	// �Ľ�Į �ﰢ�� �����
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