#include<iostream>
#include<queue>

/// <summary>
/// Silver2 ��¦��¦ - Graph �˰���
/// BFS�� �̿��� ���� Ǯ��
/// BFS�Լ����� ������ ��, ������ �ƴ� rockBridge�� ���� ���ڸ�ŭ �̵��Ѵ�
/// �̶�, �����ε� ������, �ڷε� ���� �� �� �� �ִ°� üũ�ؼ� recordVisit�� +1�Ѵ�
/// ���������� recordVisit[end]�� 0�̸� �� ���� ���� �Ҹ���, �ƴ϶�� ���⸦ �Դ����� �ִ� �Ҹ���.
/// </summary>

using namespace std;

int N(0); //���˴ٸ� ����

int rockBridge[10001]; //¡�˴ٸ� �ִ� ������ 10000�̴�.
bool visited[10001];
int recordVisit[10001];

void BFS(int start, int end)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == end)
		{
			return;
		}

		for (int i = cur + rockBridge[cur]; i <= N; i += rockBridge[cur])
		{
			if (!visited[i])
			{
				recordVisit[i] = recordVisit[cur] + 1;
				q.push(i);
				visited[i] = true;
			}
		}

		for (int i = cur - rockBridge[cur]; i >= 1; i -= rockBridge[cur])
		{
			if (!visited[i])
			{
				recordVisit[i] = recordVisit[cur] + 1;
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int start(0), end(0);

	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> rockBridge[i];
	}
	std::cin >> start >> end;

	if (start == end)
	{
		std::cout << 0 << std::endl;
		return 0;
	}

	BFS(start, end);

	if (recordVisit[end] == 0)
	{
		std::cout << -1 << std::endl;
	}
	else
	{
		std::cout << recordVisit[end] << std::endl;
	}
	return 0;
}