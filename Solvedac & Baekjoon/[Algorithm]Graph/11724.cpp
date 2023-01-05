#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 ���� ����� ���� - Graph �˰���
/// BFS�� �̿��� Ǯ��
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

	int N(0), M(0); //������ ���� N, ������ ���� M
	int U(0), V(0); //������ �� ���� U�� V
	int connetCount(0); //���ؾ��ϴ� ���� ����� ����

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