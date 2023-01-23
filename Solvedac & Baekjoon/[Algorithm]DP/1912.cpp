#include<iostream>
#include<vector>

/// <summary>
/// Silver2 ������ - DP �˰���
/// dp[i]���ٰ� ���ӵ� ���� �հ�, ���� ���� ���� ū ���� ������ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //���� N
	std::cin >> N;
	vector<int> sequence(N, 0);
	vector<int> dp(100000, 0);

	for (int i = 0; i < N; i++)
	{
		std::cin >> sequence[i];
	}

	int maxNum = sequence[0];
	dp[0] = maxNum;
	for (int i = 1; i < N; i++)
	{
		//���ӵ� ���� �հ�, ���� ���� ���� ū���� �ִ´ٴ� �ǹ�
		dp[i] = std::max(dp[i - 1] + sequence[i], sequence[i]);
		maxNum = std::max(maxNum, dp[i]);
	}

	std::cout << maxNum << std::endl;
	return 0;
}