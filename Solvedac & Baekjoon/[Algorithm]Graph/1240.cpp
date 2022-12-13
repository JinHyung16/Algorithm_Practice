#include <iostream>
#include <vector>
#include <queue>

#define MAX_DISTANCE 987654321 //int형의 최댓값
using namespace std;

/// <summary>
/// Gold5 노드 사이의 거리 - Graph 알고리즘
/// BFS를 이용하면 거리를 쉽게 찾을 수 있으나,
/// DFS와 priority queue를 이용해 백트래킹 하듯이 풀어봤다.
/// 보통 stack을 이용하는데 top에 있는걸 가져오고 top을 지우기 위해 우선순위 큐 사용
/// </summary>

int n, m;
vector<pair<int, long long>> tree[1001]; //연결된 두 점과 거리 같이 저장
long long visitedDist[1001];

void ResetDistance()
{
	for (int i = 1; i <= n; i++)
	{
		visitedDist[i] = MAX_DISTANCE; //거리를 매우 큰 수로 저장
	}
}

void FindDistance(int startNode, int endNode)
{
	priority_queue<pair<long long, int>> pq;
	pq.push(make_pair(0, startNode));

	ResetDistance();
	visitedDist[startNode] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		long long dis = -1 * pq.top().first;
		pq.pop();

		for (int i = 0; i < tree[cur].size(); i++)
		{
			int next = tree[cur][i].first;
			int curDis = tree[cur][i].second;

			if (curDis + dis < visitedDist[next])
			{
				visitedDist[next] = curDis + dis;
				pq.push(make_pair(-1 * visitedDist[next], next));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		int na, nb, dis;
		std::cin >> na >> nb >> dis;
		tree[na].push_back({ nb, dis });
		tree[nb].push_back({ na, dis });
	}

	for (int i = 0; i < m; i++)
	{
		int startNode, endNode;
		cin >> startNode >> endNode;
		FindDistance(startNode, endNode);
		std::cout << visitedDist[endNode] << std::endl;
	}
	return 0;
}