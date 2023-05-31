#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 카드 구매하기 - DP 알고리즘
/// Pi는 i개 들어있는 카드의 개수의 가격을 의미
/// 따라서 dp[i]는 카드 i개를 살 때 지불해야할 최대 금액을 담아놓으면 된다.
/// 
/// ex) dp[3]의 최댓값은 3개의 카드를 살 때 지불해야할 최대 금액을 담아야 하므로
/// dp[3] vs dp[3-1] + P1 vs dp[3-2] + P2 vs dp[3-3] + P3 중 최댓값을 담아야한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //구매하려는 카드의 개수 N
	std::cin >> N;

	//항상 price[0] = dp[0] = 0
	vector<int> price(N + 1, 0);
	vector<int> dp(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> price[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = std::max(dp[i], dp[i - j] + price[j]);
		}
	}

	std::cout << dp[N] << "\n";
	return 0;
}
