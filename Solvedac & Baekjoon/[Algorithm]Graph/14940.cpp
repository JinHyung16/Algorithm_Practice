#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 쉬운 최단거리 - Graph 알고리즘
/// BFS를 이용해 해결한다.
/// 이때 갈 수 없는곳은 -1이므로, BFS를 다 수행하고 나서 2중 for문을 통해 map에 1로 표시되었는데 visited가 false인곳들은 -1로 바꿔놓는다.
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

	//BFS를 다 돌았는데도 1이고 방문한적이 없는 곳들은 갈 수 없는곳으로 판단
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

	int n(0), m(0); //지도의 크기 세로 n, 가로 m
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