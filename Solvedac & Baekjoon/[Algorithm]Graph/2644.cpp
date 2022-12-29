#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 �̼���� - Graph �˰���
/// BFS�� �̿��� Ǯ��
/// �̼� ���谡 ������ visited ���� �ش� �̼��� ������ +1���ָ� �ȴ�.
/// </summary>

using namespace std;

int n(0); // ����� �� n
int m(0); //�θ� �ڽİ��� ������ ���� m

vector<vector<int>> relationships(101, vector<int>(101, 0)); //n�� ���� �ִ밡 100����
vector<int> visited(101, 0);

void BFS(int start, int end)
{
	queue<int> q;
	q.push(start);

	visited[start] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (relationships[cur][i] == 1 && visited[i] == 0)
			{
				//���谡 �ִµ� �湮 �������� ��� �̼� ������Ű��
				q.push(i);
				visited[i] = visited[cur] + 1;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int p1(0), p2(0); //���� �ٸ� �� ����� ��ȣ
	int x(0), y(0); //�θ� �ڽİ��� ���踦 ��Ÿ���� �� ��ȣ

	std::cin >> n;
	std::cin >> p1 >> p2;
	std::cin >> m;
	while(m--)
	{
		std::cin >> x >> y;

		//����� �������� 1�� ǥ��
		relationships[x][y] = 1;
		relationships[y][x] = 1;
	}

	BFS(p1, p2);

	if (visited[p2] != 0)
	{
		std::cout << visited[p2] - 1 << std::endl;
	}
	else
	{
		std::cout << -1 << std::endl;
	}


	return 0;
}