#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 동전1 - DP 알고리즘
/// 예제를 기준으로 1원, 2원, 5원이 주어졌을때
/// dp[1]은 1원을 만들 수 있는 경우의 수로 1개
/// dp[2]는 dp[1]의 경우의 수에다가 1원만 추가하니 2개
/// dp[3]은 2원에 1원을 더하던가, 1원에 2원을 더하던가, 아니면 1원만 3개 사용하므로 3가지다.
/// 즉 dp[i]에는 주어진 동전을 이용해 만들 수 있는 경우의 수들을 다 더해놔야한다.
/// dp[i] = dp[i] + dp[i-주어진 동전 금액] 이되는거다.
/// dp[0]은 0원을 만드는 경우는 아무것도 선택하지 않은 경우로 1가지다. 집합으로 치면 공집합 포함하는거
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0), K(0); //동전의 종류 N, 가치의 합 K
	std::cin >> N >> K;

	vector<int> coins(N, 0);	
	vector<int> dp(K + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < N; i++)
	{
		std::cin >> coins[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = coins[i]; j <= K; j++)
		{
			dp[j] = dp[j] + dp[j - coins[i]];
		}
	}

	std::cout << dp[K] << "\n";
	return 0;
}