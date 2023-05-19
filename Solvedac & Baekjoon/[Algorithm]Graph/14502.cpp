#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 연구소 - Graph 알고리즘
/// 1. 벽을 3개 세워야하기 때문에, 벽을 세울 수 있는 모든 경우를 다 돈다.
/// 2. 벽의 개수 3개를 다 소모하여 0이 됐을 때, BFS()를 돈다.
/// 
/// 이때, x축 y축을 잘 생각하여 넣는다.
/// </summary>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int maxSafeZone(0);

void BFS(vector<vector<int>>& vec)
{
	queue<pair<int, int>> q;
	
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] == 2)
			{
				//바이러스 라면
				q.push(make_pair(j, i));
			}
		}
	}

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (-1 < nextX && nextX < vec[curY].size() && -1 < nextY && nextY < vec.size() && vec[nextY][nextX] == 0)
			{
				q.push(make_pair(nextX, nextY));
				vec[nextY][nextX] = 2;
			}
		}
	}

	int safeCnt(0);
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] == 0)
			{
				safeCnt++;
			}
		}
	}
	maxSafeZone = std::max(maxSafeZone, safeCnt);
}

void CreateWall(vector<vector<int>> vec, int x, int y, int wallCnt)
{
	vec[y][x] = 1;
	if (wallCnt == 0)
	{
		BFS(vec);
		return;
	}

	for (int i = y; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] == 0)
			{
				CreateWall(vec, j, i, wallCnt - 1);
			}
		}
	}
}

int main(void)
{
	FastIO;

	int N(0), M(0); //지도의 세로 크기 N, 가로 크기 M
	std::cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				CreateWall(map, j, i, 2);
			}
		}
	}

	std::cout << maxSafeZone << "\n";
	return 0;
}