#include<iostream>
#include<vector>

/// <summary>
/// Silver4 Generations of Tribbles - DP �˰���
/// ��� �Լ��� dp�Լ��� �����ϰ� ������ �ذ��Ѵ�.
/// dp�Լ��� ������ �־��� koong�� �ǹ�
/// </summary>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T(0); //test case ���� T
	std::cin >> T;

	vector<long long> dp(68, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 68; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	vector<int> testCaseVec(T, 0);
	for (int i = 0; i < T; i++)
	{
		std::cin >> testCaseVec[i];
	}

	for (int i = 0; i < T; i++)
	{
		std::cout << dp[testCaseVec[i]] << "\n";
	}
	return 0;
}