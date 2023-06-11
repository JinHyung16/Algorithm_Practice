#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���� �ִܰŸ� - Graph �˰���
/// BFS�� �̿��� �ذ��Ѵ�.
/// �̶� �� �� ���°��� -1�̹Ƿ�, BFS�� �� �����ϰ� ���� 2�� for���� ���� map�� 1�� ǥ�õǾ��µ� visited�� false�ΰ����� -1�� �ٲ���´�.
/// </summary>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;

vector<vector<int>> result;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void BFS(int sX, int sY, int n, int m)
{
	queue<pair<int, int>> q;
	q.push(make_pair(sX, sY));
	visited[sY][sX] = true;
	
	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (nextX < 0 || m <= nextX || nextY < 0 || n <= nextY)
			{
				continue;
			}

			if (map[nextY][nextX] == 1 && !visited[nextY][nextX])
			{
				q.push(make_pair(nextX, nextY));
				visited[nextY][nextX] = true;
				result[nextY][nextX] = result[curY][curX] + 1;
			}
		}
	}

	//BFS�� �� ���Ҵµ��� 1�̰� �湮������ ���� ������ �� �� ���°����� �Ǵ�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				result[i][j] = -1;
			}
		}
	}
}

int main(void)
{
	FastIO;

	int n(0), m(0); //������ ũ�� ���� n, ���� m
	std::cin >> n >> m;

	int startX(0), startY(0);

	map.resize(n, vector<int>(m, 0));
	result.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> map[i][j];
			if (map[i][j] == 2)
			{
				startX = j;
				startY = i;
			}
		}
	}

	BFS(startX, startY, n, m);
	
	for (int i = 0; i < n; i++)
	{
		for(int j =  0; j < m; j++)
		{
			std::cout << result[i][j] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}