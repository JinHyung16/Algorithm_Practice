#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver1 지름길 - DP 알고리즘
/// (고속도로의 길이 < 지름길 도착) || ((지름길 도착)-(지름길 시작) < 지름길 길이) 인경우 무시
/// pair를 통해 2차원 배열에서 해당 위치의 값을 {key, value}느낌으로 저장할 수 있다.
/// </summary>


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	vector<int> dp(10000, 10000); //각 길이별 이동해야할 거리 체크하기, 매우 큰 수로 초기화
	vector<pair<int, int>> shortPath[10000]; //지름길 정보 저장
	int N(0), D(0); //지름길 개수, 고속도로 길이
	int start(0), end(0), shortPathCost(0);

	std::cin >> N >> D;
	for (int i = 0; i < N; i++)
	{
		std::cin >> start >> end >> shortPathCost;
		if (end > D || (end - start) < shortPathCost)
		{
			continue;
		}
		//지름길 도착 구간에다가 지름길의 시작 위치와, 길이 저장해두기
		shortPath[end].push_back({ start, shortPathCost });
	}

	dp[0] = 0; //0미터 가는건 0미터
	for (int i = 1; i <= D; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < (int)shortPath[i].size(); j++)
		{
			// 현재 움직인 cost는 지름길의 start지점 + 지름길의 길이
			int curPathCost = dp[shortPath[i][j].first] + shortPath[i][j].second;
			dp[i] = std::min(dp[i], curPathCost);
		}
	}

	std::cout << dp[D] << std::endl;
	return 0;
}