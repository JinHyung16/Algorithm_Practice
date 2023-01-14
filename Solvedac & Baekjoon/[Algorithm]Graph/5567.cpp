#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 ��ȥ�� - Graph �˰���
/// BFS�� ���� ���� Ǯ��
/// ���� ������ ����, �ᱹ ģ���� ����� �� 1������ ����Ǿ�� ģ����
/// </summary>

using namespace std;

int N(0), M(0); //����� ������ �� N, ����Ʈ ���� M
vector<vector<int>> friends(502, vector<int>(502, 0));
vector<bool> visited(502, false);
int inviteCnt(0);

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur != 1)
		{
			//������� �������� ģ���� �ƴ϶��
			for (int i = 2; i <= N; i++)
			{
				//����� ģ���� �������� �� 1���� ���� �ȴ�
				if (friends[cur][i] == 1 && !visited[i])
				{
					visited[i] = true;
					inviteCnt++;
					continue;
				}
			}
		}
		else
		{
			//������� �������� ģ�����
			for (int i = 1; i <= N; i++)
			{
				//1�� ����̷� ����� ���غ��� ���� �ȴ�
				if (friends[cur][i] == 1 && !visited[i])
				{
					visited[i] = true;
					q.push(i);
					inviteCnt++;
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int u(0), v(0);

	std::cin >> N;
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		std::cin >> u >> v;
		//���� ���谡 ������ 1�� ǥ��
		friends[u][v] = 1;
		friends[v][u] = 1;
	}

	BFS(1);
	std::cout << inviteCnt << std::endl;

	return 0;
}