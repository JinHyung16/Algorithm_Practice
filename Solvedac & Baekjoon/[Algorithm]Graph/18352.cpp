#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 Ư�� �Ÿ��� ���� ã�� - Graph �˰���
/// �ܹ��� �׷������� ������ ���ø� �̾��ش�.
/// �� �� BFS�� ���� ���鼭 visited�� �ʱ� -1�� �س���,
/// �ʱ� ���� ������ visited�� 0���� �ʱ�ȭ�ϰ� �� ���� ���ð�
/// �湮 �����ϴٸ� ���� ������ visited ������ +1�Ѵ�
/// ���� �� �湮�ߴٸ�, �Ÿ��� K�� ���õ��� result�� ��� ������ �����Ѵ�.
/// </summary>

using namespace std;

int N(0), M(0), K(0), X(0); //���� ���� N, ������ ���� M, �Ÿ� ���� K, ��� ������ ��ȣ X
vector<vector<int>> graph;
vector<int> visited;
vector<int> result; //�Ÿ��� K�� ���� �ֱ�

void BFS()
{
	queue<int> q;
	q.push(X);

	visited[X] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		//���� ���ø� �������� ����� ���� Ž���ϱ�
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i]; //���� ���� ��ȣ�� �̵�
			if (visited[next] == -1)
			{
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == K)
		{
			//�Ÿ��� K�� ���� ��ȣ ������������ �ֱ�
			result.push_back(i);
		}
	}
}
int main(void)
{
	FastIO;
	
	std::cin >> N >> M >> K >> X;

	graph.resize(N + 1);
	visited.resize(N + 1, -1);
	//graph = vector<vector<int>>(N + 1);

	for (int i = 0; i < M; i++)
	{
		int start, end;
		std::cin >> start >> end;
		//�ܹ��� �׷������ ������, start���� end�� �̾��ش�
		graph[start].push_back(end);
	}

	BFS();

	if (result.size() == 0)
	{
		std::cout << -1 << "\n";
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			std::cout << result[i] << "\n";
		}
	}
	return 0;
}