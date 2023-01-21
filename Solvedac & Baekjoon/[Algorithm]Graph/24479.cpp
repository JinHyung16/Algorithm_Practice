#include<iostream>
#include<vector>
#include<algorithm>

/// <summary>
/// Silver2 �˰��� ���� - ���� �켱 Ž�� 1 - Graph �˰���
/// ��Ϳ� DFS�� �̿��� Ǯ�̴�.
/// std::endl�� ����ϴϱ� �ð� �ʰ��� ���Դ�. "\n"�� �̿�����!
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
		//������ ���� �������� �湮�� ���ؼ�
		std::sort(graph[i].begin(), graph[i].end());
	}

	DFS(R);
	for (int i = 1; i <= N; i++)
	{
		std::cout << visited[i] << "\n";
	}

	return 0;
}