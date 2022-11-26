#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver2 �������� �� - DP �˰���
/// �Ž����� �ּ� ���� �ִ°Ŷ� ����ϰ� �����غ���!
/// 


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n = 0;
	std::cin >> n;

	vector<int> dp(n+1, 0);
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			if (dp[i] > dp[i - (j * j)] + 1)
			{
				dp[i] = dp[i - (j * j)] + 1;
			}
		}
	}

	std::cout << dp[n] << std::endl;
	dp.clear();
	return 0;
}