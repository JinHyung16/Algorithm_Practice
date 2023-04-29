#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 특정한 최단 경로 - Graph 알고리즘
/// 다익스트라를 활용하여 해결한다.
/// 주어진 두 정점 V1, V2에 대해 루트1: start -> v1 -> v2 -> N 루트2: start -> v2 -> v1 -> N
/// 1. start -> v1 과 start -> v2까지의 거리를 구한 다익스트라
/// 2. v1 -> v2까지의 거리를 구한 다익스트라인데 여기서 양방향으로 v2 -> v1은 안구해도 괜찮다.
/// 3. v2 -> N을 구하기 위한 다익스트라로 v1->v2를 구할 때 구할 수 있으니 패스
/// 이렇게 다익스트라를 세번 실행한 값을 저장해두고, 그 중 루트가 더 작을걸 구한다.
/// </summary>

using namespace std;

int N(0), E(0); //정점의 개수 N, 간선의 개수 E
int V1(0), V2(0);
vector<pair<int, int>> graph[801];
vector<int> distVec(801, 0);

void DistanceReset()
{
	for (int i = 0; i <= N; i++)
	{
		distVec[i] = 987654321;
	}
}

void BFS_Dijkstar(int start)
{
	DistanceReset();
	distVec[start] = 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	
	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int curPos = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[curPos].size(); i++)
		{
			int nextPos = graph[curPos][i].first;
			int nextDist = graph[curPos][i].second;

			if (nextDist + curDist < distVec[nextPos])
			{
				distVec[nextPos] = nextDist + curDist;
				pq.push(make_pair(distVec[nextPos], nextPos));
			}
		}
	}
}

int main(void)
{
	FastIO;

	int result(987654321);

	std::cin >> N >> E;

	while(E--)
	{
		int a(0), b(0), c(0);
		std::cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	std::cin >> V1 >> V2;

	BFS_Dijkstar(1);
	int startToV1 = distVec[V1];
	int startToV2 = distVec[V2];

	BFS_Dijkstar(V1);
	int v1ToV2 = distVec[V2]; //v2ToV1이랑 거리가 같다. 왜냐면 양방향 그래프니깐
	int v1ToN = distVec[N];

	BFS_Dijkstar(V2);
	int v2ToN = distVec[N];

	result = std::min(result, (startToV1 + v1ToV2 + v2ToN));
	result = std::min(result, (startToV2 + v1ToV2 + v1ToN));

	if (v1ToV2 == 987654321 || result == 987654321)
	{
		std::cout << -1 << "\n";
	}
	else 
	{
		std::cout << result << "\n";
	}
	return 0;
}