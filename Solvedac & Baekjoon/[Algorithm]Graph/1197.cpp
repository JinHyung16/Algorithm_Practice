#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 최소 소패닝 트리 - Graph 알고리즘
/// 스패닝 트리는 모든 정점이 연결되어 있으므로, 입력시 모든 정점을 이어준다.
/// MST 해결법 중 프림을 이용한다. 그러므로 priority_queue가 필요하다.
/// 정점 개수 V, 간선 개수 E에 대해 간선의 수가 매우 많을때 유리한게 프림이며
/// O(ElogV)만큼 걸린다.
/// </summary>

using namespace std;

vector<pair<int, int>> graph[10001];
vector<bool> visited(10001, false);
long long mstCost = 0;

void MST_Prim(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start)); //cost를 순서로 오름차순 정렬하기 위해 (코스트, 노드 위치)순서로 저장

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		//방문한 노드면 그냥 넘기고, 아니라면 minCost에 더하기
		if (visited[cur])
		{
			continue;
		}

		visited[cur] = true;
		mstCost += curCost;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second;
			
			pq.push(make_pair(nextCost, next));
		}
	}
}

int main(void)
{
	FastIO;

	int V(0), E(0); //정점의 개수 V, 간선의 개수 E
	std::cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int a(0), b(0), c(0); //a정점 b정점 사이의 가중치 c
		std::cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	MST_Prim(1);
	
	std::cout << mstCost << "\n";
	return 0;
}
