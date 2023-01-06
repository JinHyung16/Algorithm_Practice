#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 Ʈ���� �θ� ã�� - Graph �˰���
/// BFS�� �̿��� Ǯ��
/// </summary>

using namespace std;

const int MAX_SIZE = 100001;

vector<vector<int>>	graph(MAX_SIZE);
vector<int> parent(MAX_SIZE, 0);

void BFS(int root)
{
	queue<int> q;
	q.push(root);
	parent[root] = root;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (parent[next] == 0)
			{
				q.push(next);
				parent[next] = cur;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //����� ���� N
	std::cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int u(0), v(0);
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	BFS(1); //root�� 1���� ����

	for (int i = 2; i <= N; i++)
	{
		std::cout << parent[i] << "\n";
	}
	return 0;
}