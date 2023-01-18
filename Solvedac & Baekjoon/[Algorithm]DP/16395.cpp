#include<iostream>
#include<vector>

/// <summary>
/// Silver5 �Ľ�Į�� �ﰢ�� - DP �˰���
/// dp[i][j] = dp[i-1][j-1] + dp[i-1][j]��.
/// �̴� ���� ���� �� + ���� ���� ������ �Ľ�Į ���� ������.
/// ���۽� �� ���� 1�̶�� �����Ƿ� �� ���� ù ��° ���� 1�� �ʱ�ȭ �صд�
/// �̶� k <= n <= 30�̹Ƿ� ���� ����� 30������ ���������Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0), K(0); //n��° �� k��° ��

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