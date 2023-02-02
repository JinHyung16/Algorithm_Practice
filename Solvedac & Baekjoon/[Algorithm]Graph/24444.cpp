#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 알고리즘 수업 - 너비 우선 탐색1 - Graph 알고리즘
/// 인접 정점은 오름차순으로 방문한다고 했으니, 그래프를 만들어 주고
/// 정점의 수 만큼 반복문을 돌면서 sort를 오름차순으로 한 뒤 BFS 실행한다
/// </summary>

using namespace std;
vector<int> graph[100001];
vector<bool> visited(100001, false);
vector<int> result(100001);
int visitCheck(0);

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	visitCheck++;
	result[start] = visitCheck; //처음 방문한 곳은 1로

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		//노드의 연결된 곳 방문
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (!visited[next])
			{
				visitCheck++;
				result[next] = visitCheck;
				q.push(next);
				visited[next] = true;
			}
		}
	}
}
int main(void)
{
	FastIO;

	int N(0), M(0), R(0); //정점의 수 N, 간선의 수 M, 시작 정점 R
	std::cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		std::sort(graph[i].begin(), graph[i].end());
	}

	BFS(R);

	for (int i = 1; i <= N; i++)
	{
		std::cout << result[i] << "\n";
	}
	return 0;
}