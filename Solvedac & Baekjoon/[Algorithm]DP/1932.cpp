#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���� �ﰢ�� - DP �˰���
/// (i,j)�� �������� ���� ���� ��� �κп� ���� �ְ� ������ �������� ���ϸ鼭 Ǭ��.
/// �׷��� ���ǿ� ���� if���� ����� �ذ��Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //�ﰢ���� ũ�� N
	std::cin >> N;
	vector<vector<int>>dp(N + 5, vector<int>(N + 5, 0));

	dp[0][0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			std::cin >> dp[i][j];
		}
	}

	int maxSum = dp[1][1];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i + 1; j++)
		{
			if (j == 1)
			{
				//�� ���� �� �ٷ� ���� ���� �����Ƿ� �ش� �κи� ���� �����´�.
				dp[i][j] += dp[i - 1][j];
			}
			else if (j == i)
			{
				//�� ���� �� ���ʿ��� ���� �κи� ���� �����Ƿ� �ش� �κи� ���� �����´�.
				dp[i][j] += dp[i - 1][j - 1];
			}
			else
			{
				//�� �ܴ� �ٷ��� �Ǵ� ���� �밢������ ���� �����´�
				dp[i][j] += std::max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
			maxSum = std::max(dp[i][j], maxSum);
		}
	}

	std::cout << maxSum << "\n";
	return 0;
}