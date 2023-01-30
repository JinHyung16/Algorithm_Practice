#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 아기 상어2 - Graph 알고리즘
/// BFS를 이용한 풀이
/// 2중 pair대신 struct을 이용하자
/// queue<pair<painr<int,int>, int>> 를 struct을 이용하면 간단하게 표기할 수 있다.
/// </summary>

using namespace std;

int N, M; //공간의 크기 N * M -> N은 Y줄, M은 X줄 의미
vector<vector<int>> grid(55, vector<int>(55, 0));
vector<vector<bool>> visited(55, vector<bool>(55, false));

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int result = 0;

void ResetVector()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = false;
		}
	}
}

struct ZoneInfo
{
	int X, Y, ZoneCnt;
	ZoneInfo(int x, int y, int cnt)
	{
		X = x;
		Y = y;
		ZoneCnt = cnt;
	}
};
int BFS(int x, int y)
{
	ResetVector();

	queue<ZoneInfo> q;
	q.push(ZoneInfo(x, y, 0));

	visited[y][x] = true;

	while (!q.empty())
	{
		int curX = q.front().X;
		int curY = q.front().Y;
		int curCnt = q.front().ZoneCnt;

		q.pop();

		if (grid[curY][curX] == 1)
		{
			return curCnt;
		}

		for (int i = 0; i < 8; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N)
			{
				if (!visited[nextY][nextX])
				{
					visited[nextY][nextX] = true;
					q.push(ZoneInfo(nextX, nextY, curCnt + 1));
				}
			}
		}
	}

	return 0;
}

int main(void)
{
	FastIO;

	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> grid[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == 0)
			{
				result = std::max(result, BFS(j, i));
			}
		}
	}

	std::cout << result << "\n";

	return 0;
}