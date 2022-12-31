#include<iostream>
#include<vector>

/// <summary>
/// Silver4 돌 게임 2 - DP 알고리즘
/// 게임은 상근이가 먼저 시작한다
/// 상근이 기준 dp[i-1]과 dp[i-3]이 1이면 지는 상황, 0이면 이기는 상황이다
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int stonN(0); //돌 갯수 N
	vector<int> dp(1001, 0);

	std::cin >> stonN;
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;

	for (int i = 4; i <= stonN; i++)
	{
		if (std::min(dp[i - 1], dp[i - 3]) == 1) //남은 돌이 1이라는 의미를 파악하기
		{
			//상근이 기준 상근이가 가져가고 남은 돌이 1개면 다음 창영이가 돌을 가져가니 상근이가 이긴거
			dp[i] = 0;
		}
		else
		{
			//아니면 상근이가 진 경우가 된다
			dp[i] = 1;
		}
	}

	if (dp[stonN] == 1)
	{
		std::cout << "SK" << std::endl;
	}
	else
	{
		std::cout << "CY" << std::endl;
	}
	return 0;
}