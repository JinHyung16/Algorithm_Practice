#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 알고리즘 수업 - 너비 우선 탐색 2 - Graph 알고리즘
/// 이전의 오름차순에서 내림차순으로만 변경하면 된다.
/// 내림차순 정렬시 두가지 방법이 있으니 기억하자
/// </summary>

using namespace std;

int N(0), M(0), R(0); //정점의 수 N, 간선의 수 M, 시작 정점 R
vector<int> graph[100001];
vector<bool> visited(100001, false);
vector<int> result(100001);
int visitCheck (0);

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	
	visited[start] = true;

	//visitCheck이 0이므로 1증가 시키면 첫 시작지점은 1이 된다.
	visitCheck++;
	result[start] = visitCheck;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		
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
	
	std::cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//내림 차순 탐색을 위한
	for (int i = 1; i <= N; i++)
	{
		//std::sort(graph[i].rbegin(), graph[i].rend());
		std::sort(graph[i].begin(), graph[i].end(), std::greater<int>());
	}

	BFS(R);

	for (int i = 1; i <= N; i++)
	{
		std::cout << result[i] << "\n";
	}
	return 0;
}