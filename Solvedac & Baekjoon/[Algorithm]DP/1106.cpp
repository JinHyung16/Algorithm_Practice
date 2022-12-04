#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Gold5 호텔 - DP 알고리즘
/// DP문제의 핵심은 1부터 증가시키고자 하는 고객수 만큼 다 돌면서
/// 딱 1번만 계산해서 저장해놓는다.
/// dp배열의 크기는 늘리려는 C명의 고객 범위 최대가 1000이고,
/// 비용으로 얻는 고객의 수 범위의 최대가 100으로 두개를 곱하면 100000이다
/// </summary>

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int clientNum = 0; //C명 증가시키려는 고객의 수
	int cities = 0; //홍보하려는 도시 수 N

	std::cin >> clientNum >> cities;
	vector<int> client(1001, 0); //얻을 수 있는 고객의 수
	vector<int> cost(20, 0); //각 도시에서 홍보할 때 드는 비용
	client[0] = 0;
	cost[0] = 0;

	for (int i = 1; i <= cities; i++)
	{
		std::cin >> cost[i] >> client[i];
	}

	vector<int> dp(100001, 0); //범위가 100000인데 거기에 +1해준거다. 왜 범위가 나온지는 맨 위 주석 참고
	dp[0] = 0;
	for (int i = 1; i <= cities; i++)
	{
		for (int j = 1; j <= 100000; j++)
		{
			if (j - cost[i] >= 0)
			{
				dp[j] = std::max(dp[j], dp[j - cost[i]] + client[i]);
			}
		}
	}

	for (int i = 1; i <= 100000; i++)
	{
		if (clientNum <= dp[i])
		{
			std::cout << i << "\n";
			break;
		}
	}

	return 0;
}