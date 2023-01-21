#include<iostream>
#include<vector>
#include<algorithm>

/// <summary>
/// Silver2 알고리즘 수업 - 깊이 우선 탐색 1 - Graph 알고리즘
/// 재귀와 DFS를 이용한 풀이다.
/// std::endl로 출력하니깐 시간 초과가 나왔다. "\n"를 이용하자!
/// </summary>

using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0, };
int visitCnt(0);

void DFS(int start)
{
	visitCnt++;
	visited[start] = visitCnt;

	for (auto& edge : graph[start])
	{
		if (visited[edge])
		{
			continue;
		}
		DFS(edge);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

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
		//인접한 노드는 오름차순 방문을 위해서
		std::sort(graph[i].begin(), graph[i].end());
	}

	DFS(R);
	for (int i = 1; i <= N; i++)
	{
		std::cout << visited[i] << "\n";
	}

	return 0;
}