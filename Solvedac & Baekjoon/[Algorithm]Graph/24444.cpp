#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 �˰��� ���� - �ʺ� �켱 Ž��1 - Graph �˰���
/// ���� ������ ������������ �湮�Ѵٰ� ������, �׷����� ����� �ְ�
/// ������ �� ��ŭ �ݺ����� ���鼭 sort�� ������������ �� �� BFS �����Ѵ�
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
	result[start] = visitCheck; //ó�� �湮�� ���� 1��

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		//����� ����� �� �湮
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

	int N(0), M(0), R(0); //������ �� N, ������ �� M, ���� ���� R
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