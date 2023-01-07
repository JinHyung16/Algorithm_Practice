#include<iostream>
#include<vector>

/// <summary>
/// Silver5 �� ���� - DP �˰���
/// dp�� ���� Ƚ���� �����س��´�.
/// dp[N] = min(dp[N-1] + 1, dp[N-3] + 1)�� Ȧ���� ����� ��, ¦���� â���� ��
/// ���� Ƚ���� Ȧ���� �Ҹ���, ������ ���� ������ ����� ����̰� �ǹǷ� ����̰� ���̶� �Ҹ���
/// </summary>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //�� ���� N
	vector<int> dp(1001, 0);

	std::cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = std::min(dp[i - 1] + 1, dp[i - 3] + 1);
	}

	if (dp[N] % 2 == 1)
	{
		//���� Ƚ���� Ȧ�����
		std::cout << "SK" << std::endl;
	}
	else
	{
		//���� Ƚ���� ¦�����
		std::cout << "CY" << std::endl;
	}
	return 0;
}