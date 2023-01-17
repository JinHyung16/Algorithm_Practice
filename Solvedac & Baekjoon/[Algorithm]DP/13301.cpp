#include<iostream>
#include<vector>

/// <summary>
/// Silver5 타일 장식물 - DP 알고리즘
/// dp[i]는 i개의 타일 장식물 둘레 길이를 담고있다
/// dp[1]은 길이 1짜리 타일 1개의 둘레
/// dp[2]는 길이 1짜리 2개를 합친 타일의 둘레
/// dp[3]은 길이 1짜리 2개와 길이 2짜리 1개 타일을 합친 둘레
/// 기본은 피보나치 수열을 따른다. 그러나 dp를 어떤식으로 설정하느냐에 따라
/// 식이 간결하게 사용될 수 있다/
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //타일의 개수 n
	std::cin >> N;

	vector<long long> dp(81);
	dp[0] = 0;
	dp[1] = 4;
	dp[2] = 6;
	dp[3] = 10;
	dp[4] = 16;

	for (int i = 5; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	std::cout << dp[N] << std::endl;
	return 0;
}