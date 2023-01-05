#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 연결 요소의 개수 - Graph 알고리즘
/// BFS를 이용한 풀이
/// </summary>

using namespace std;

vector<int> graph[1001];
vector<bool> visited(1001, false);

void BFS(int start)
{
	queue<int> q;
	q.push(start);

	visited[start] = true;

	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();

		for (int i = 0; i < graph[curNode].size(); i++)
		{
			if (!visited[graph[curNode][i]])
			{
				visited[graph[curNode][i]] = true;
				q.push(graph[curNode][i]);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0), M(0); //정점의 개수 N, 간선의 개수 M
	int U(0), V(0); //간선의 양 끝점 U와 V
	int connetCount(0); //구해야하는 연결 요소의 개수

	std::cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		std::cin >> U >> V;
		graph[U].push_back(V);
		graph[V].push_back(U);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			BFS(i);
			connetCount++;
		}
	}

	std::cout << connetCount << std::endl;
	return 0;
}