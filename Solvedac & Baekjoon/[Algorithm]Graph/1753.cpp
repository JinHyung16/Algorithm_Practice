#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 최단 경로 - Graph 알고리즘
/// 다익스트라를 이용한 풀이다.
/// </summary>

using namespace std;

vector<pair<int, int>> graph[20010];
vector<int> distVec(20010, 987654321);


void BFS_Dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start)); //거리, 현재 노드순으로 저장

	distVec[start] = 0;

	while (!pq.empty())
	{
		int curNode = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[curNode].size(); i++)
		{
			int nextNode = graph[curNode][i].first;
			int nextDist = curDist + graph[curNode][i].second;

			if (nextDist < distVec[nextNode])
			{
				distVec[nextNode] = nextDist;
				pq.push(make_pair(nextDist, nextNode));
			}
		}
	}
}

int main(void)
{
	FastIO;
	
	int V(0), E(0); //정점의 개수 V, 간선의 개수 E
	int startNum(0); //시작 지점 정점의 번호
	
	std::cin >> V >> E;
	std::cin >> startNum;
	while (E--)
	{
		int u(0), v(0), w(0); //u에서 v로 가는 가중치 w인 간선
		std::cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	BFS_Dijkstra(startNum);

	for (int i = 1; i <= V; i++)
	{
		if (distVec[i] < 987654321)
		{
			std::cout << distVec[i] << "\n";
		}
		else
		{
			std::cout << "INF" << "\n";
		}
	}

	return 0;
}