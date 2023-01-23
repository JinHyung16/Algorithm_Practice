#include<iostream>
#include<vector>

/// <summary>
/// Silver2 연속합 - DP 알고리즘
/// dp[i]에다가 연속된 수의 합과, 현재 수를 비교해 큰 수를 넣으면된다.
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //정수 N
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
		//연속된 수의 합과, 현재 수의 합중 큰것을 넣는다는 의미
		dp[i] = std::max(dp[i - 1] + sequence[i], sequence[i]);
		maxNum = std::max(maxNum, dp[i]);
	}

	std::cout << maxNum << std::endl;
	return 0;
}