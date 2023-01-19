#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 양 한마리... 양 두마리... - Graph 알고리즘
/// BFS를 이용한 문제 풀이
/// Reset시킬 때, 배열의 전체를 할 필요없이 H와 W만큼 하자! 실제 사용 구간이니깐
/// 재귀+DFS형식 보단 BFS로 진행하는게 stack 호출이 적을거 같아 사용했다.
/// </summary>

using namespace std;

int H(0), W(0); //그리드의 높이 H, 너비 W
vector<vector<char>> grid(100, vector<char>(100, ' '));
vector<vector<bool>> visited(100, vector<bool>(100, false));

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void ResetArray()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			grid[i][j] = ' ';
			visited[i][j] = false;
		}
	}
}

void BFS(int x, int y)
{
	queue<pair<int, int >> q;
	q.push(make_pair(x, y));

	visited[y][x] = true;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (0 <= nextX && nextX < W && 0 <= nextY && nextY < H)
			{
				if (!visited[nextY][nextX] && grid[nextY][nextX] == '#')
				{
					visited[nextY][nextX] = true;
					q.push({ nextX, nextY });
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

	int testCase(0);
	std::cin >> testCase;

	while (testCase--)
	{
		int sheepCount = 0;
		ResetArray();

		std::cin >> H >> W;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				std::cin >> grid[i][j];
			}
		}

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (!visited[i][j] && grid[i][j] == '#')
				{
					BFS(j, i);
					sheepCount += 1;
				}
			}
		}

		std::cout << sheepCount << std::endl;
	}

	return 0;
}