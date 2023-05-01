#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 최소비용 구하기 - Graph 알고리즘
/// 다익스트라를 이용한 풀이다.
/// 다익스트라 알고리즘은 하나의 정점에서 다른 모든 정점으로 갈 수 있는 최단 경로를 이야기한다.
/// </summary>

using namespace std;

vector<pair<int, int>> city[1001];
vector<int> costVec(1001, 987654321);

void BFS_Dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	costVec[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		//costVect이 더 최단이면 굳이 검사안하고 넘겨도된다. 왜냐면 이미 그게 최소 비용이니깐.
		if (costVec[cur] < curCost)
		{
			continue;
		}

		for (int i = 0; i < city[cur].size(); i++)
		{
			int next = city[cur][i].first;
			int nextCost = curCost + city[cur][i].second;

			if (nextCost < costVec[next])
			{
				costVec[next] = nextCost;
				pq.push(make_pair(costVec[next], next));
			}
		}
	}
}
int main(void)
{
	FastIO;
	
	int N(0), M(0); //N개의 도시 M개의 버스
	std::cin >> N >> M;

	while (M--)
	{
		int start(0), end(0), cost(0);
		std::cin >> start >> end >> cost;
		city[start].push_back(make_pair(end, cost));
	}
	int S(0), E(0); //출발점과 도착점
	std::cin >> S >> E;

	BFS_Dijkstra(S);

	std::cout << costVec[E] << "\n";
	return 0;
}