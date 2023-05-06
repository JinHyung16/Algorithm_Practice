#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 최소비용 구하기2 - Graph 알고리즘
/// 다익스트라 개념을 이용한 해결
/// start에서 다음 지점으로 이동했을 때, beforeRoute[다음 지점] = 이전 지점을 넣어둔다.
/// 넣어둔 경로를 역으로 출력한다.
/// </summary>

using namespace std;

vector<pair<int, int>> city[1001];
vector<int> costVec(1001, 987654321);
vector<int> route;
vector<int> beforeRoute(1001, 0);

void BFS_Dijkstra(int startNode)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, startNode));
	costVec[startNode] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if (costVec[cur] < curCost)
		{
			continue;
		}

		for (int i = 0; i < city[cur].size(); i++)
		{
			int next = city[cur][i].first;
			int nextCost = city[cur][i].second;

			if (curCost + nextCost < costVec[next])
			{
				costVec[next] = curCost + nextCost;
				pq.push(make_pair(costVec[next], next));
				beforeRoute[next] = cur;
			}
		}
	}
}

int main(void)
{
	FastIO;

	int N(0), M(0); //도시의 개수 N, 버스의 개수 M
	int s(0), e(0), c(0); //시작, 도착, 비용
	std::cin >> N;
	std::cin >> M;

	while (M--)
	{
		std::cin >> s >> e >> c;
		city[s].push_back(make_pair(e, c));
	}

	int start(0), end(0);
	std::cin >> start >> end;

	BFS_Dijkstra(start);

	//before route에 도착지점 index에 시작 지점 루트를 넣어났다.
	//그러니 역으로 route에 push하면서 넣는다.
	int temp = end;
	while (temp)
	{
		route.push_back(temp);
		temp = beforeRoute[temp];
	}

	std::cout << costVec[end] << "\n";
	std::cout << route.size() << "\n";
	for (int i = route.size() - 1; 0 <= i; i--)
	{
		std::cout << route[i] << " ";
	}
	std::cout << "\n";

	return 0;
}