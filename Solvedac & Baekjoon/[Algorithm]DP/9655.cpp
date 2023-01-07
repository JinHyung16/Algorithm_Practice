#include<iostream>
#include<vector>

/// <summary>
/// Silver5 돌 게임 - DP 알고리즘
/// dp는 게임 횟수를 저장해놓는다.
/// dp[N] = min(dp[N-1] + 1, dp[N-3] + 1)이 홀수면 상근이 승, 짝수면 창용이 승
/// 게임 횟수가 홀수란 소리는, 마지막 돌을 가져갈 사람이 상근이가 되므로 상근이가 승이란 소리다
/// </summary>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //돌 개수 N
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
		//게임 횟수가 홀수라면
		std::cout << "SK" << std::endl;
	}
	else
	{
		//게임 횟수가 짝수라면
		std::cout << "CY" << std::endl;
	}
	return 0;
}