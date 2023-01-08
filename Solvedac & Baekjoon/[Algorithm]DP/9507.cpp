#include<iostream>
#include<vector>

/// <summary>
/// Silver4 Generations of Tribbles - DP 알고리즘
/// 재귀 함수를 dp함수라 생각하고 문제를 해결한다.
/// dp함수는 문제에 주어진 koong을 의미
/// </summary>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T(0); //test case 개수 T
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