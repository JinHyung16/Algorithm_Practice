#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 토마토 - 그래프 알고리즘
/// 3차원 벡터를 선언하여 해결한다. 기존 2차원 BFS에서 높이가 추가되었다 생각한다. 이때 높이를 h또는 z라 부른다
/// 1. 먼저 입력받으면서 토마토가 있는 위치들을 queue에 담아둔다. 이때 x,y,z순서로 push
/// 2. x, y, z축에 대해 이동가능하게 dx, dy, dz배열을 만든다.
/// 3. queue를 돌면서 해당 위치에서 z축방향, y축방향, x축방향으로 BFS를 실행한다. 그러면서 ripenDay를 증가시킨다.
/// 4. 토마토가 있는 모든 지점의 탐색을 맞췄다면, 전체 토마토가 심어진 상자를 보면서 하나라도 0인 부분이 있는지 확인한다.
/// 5. 있다면 -1을 return 없다면 ripenDay를 반환한다.
/// 이때 ripenDay는 토마토 탐색시 while문에서 마지막에 q 지우고 q가 null인 상태에서 한번 더 수행하고 나서 멈추기에 -1을 해준다.
/// </summary>

using namespace std;

int M(0), N(0), H(0); //가로 M, 세로 N, 쌓아 올려지는 상자 수 H
vector<vector<vector<int>>> tomato(102, vector<vector<int>>(102, vector<int>(102)));
queue<pair<pair<int, int>, int>> q; //익은 토마토를 담아놓는다.

//높이, 상하, 좌우 순으로 담는다
int dx[6] = { 0, 0, 1, 0, 0, -1 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 1, 0, 0, -1, 0, 0 };

int BFS()
{
	int ripenDay = 0;
	while (!q.empty())
	{
		int qSize = q.size();
		ripenDay++;

		for (int i = 0; i < qSize; i++)
		{
			int curX = q.front().first.first;
			int curY = q.front().first.second;
			int curZ = q.front().second;
			q.pop();

			for (int j = 0; j < 6; j++)
			{
				int nextX = curX + dx[j];
				int nextY = curY + dy[j];
				int nextZ = curZ + dz[j];

				if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N && 0 <= nextZ && nextZ < H
					&& tomato[nextZ][nextY][nextX] == 0)
				{
					q.push({ { nextX, nextY }, nextZ });
					tomato[nextZ][nextY][nextX] = 1;
				}
			}
		}
	}

	//익지 않은 토마토가 있는지 확인
	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (tomato[h][i][j] == 0)
				{
					return -1;
				}
			}
		}
	}

	return (ripenDay - 1);
}

int main(void)
{
	FastIO;

	std::cin >> M >> N >> H;

	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				std::cin >> tomato[h][i][j];
				if (tomato[h][i][j] == 1)
				{
					q.push({ {j,i},h });
				}
			}
		}
	}

	int result = BFS();
	std::cout << result << "\n";
	return 0;
}