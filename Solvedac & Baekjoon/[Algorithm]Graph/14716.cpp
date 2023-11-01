#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 현수막 - Graph 알고리즘
/// DFS를 통해 해결한다.
/// 문제에서 상,하,좌,우 대각선으로 총 8방향으로 이동 가능하니
/// 이를 미리 dx, dy 배열에 담아둔다.
/// </summary>

int M = 0, N = 0; //현수막의 크기 행 M, 열 N
int map[251][251] = { 0, };
bool visited[251][251] = { false, };

int dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 }; //좌우 움직임
int dy[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }; //상하 움직임

void DFS(int x, int y)
{
	visited[y][x] = true;

	for (int i = 0; i < 8; i++)
	{
		int nextX = dx[i] + x;
		int nextY = dy[i] + y;
		if (nextX < 0 || N <= nextX || nextY < 0 || M <= nextY)
			continue;
		if (visited[nextY][nextX] || map[nextY][nextX] == 0)
			continue;
		DFS(nextX, nextY);
	}
}

int main(void)
{
	FastIO;
	
	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && map[i][j] == 1)
			{
				DFS(j, i);
				result++;
			}
		}
	}

	cout << result << "\n";
	return 0;
}