#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 퇴사 - DP 알고리즘
/// dp[i]는 i일까지 일했을 때 얻은 최대 수익을 의미한다.
/// dp[i]에는 i일에서 걸리는 시간까지의 dp값과 i일에 일한 보수 vs i날 일하지 않고 그 다음날 일한 보수값을 비교하여 큰 값을 넣어둔다.
/// N일부터 거꾸로 오면서 최댓값을 넣어둔다.
/// 
/// 이때, i일에서 상담이 걸리는 시간을 합친 값이 N을 지나면 상담을 할 수 없기에, dp[i]는 dp[i+1]값을 저장하고 continue해버린다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //일하는 기간 N
	int maxRevenue(-1); //최대 수익

	vector<pair<int, int>> job;
	vector<int> dp(20, 0);
	std::cin >> N;

	for(int i = 0; i < N; i++)
	{
		int time(0), price(0);
		std::cin >> time >> price;
		job.push_back(make_pair(time, price));
	}

	for (int i = N - 1; 0 <= i; i--)
	{
		if (N < i + job[i].first)
		{
			dp[i] = dp[i + 1]; //dp[i]의 i+1값을 넣어두고 끝내버린다.
			continue;
		}
		dp[i] = std::max(dp[i + job[i].first] + job[i].second, dp[i + 1]);
	}
	
	for (int i = 0; i < N; i++)
	{
		maxRevenue = std::max(maxRevenue, dp[i]);
	}
	std::cout << maxRevenue << "\n";
	return 0;
}
