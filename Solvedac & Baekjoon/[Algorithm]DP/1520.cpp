#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold3 내리막 길 - DP 알고리즘
/// dp[i][j] = a는 (j,i)로 가는 최소 경우의 수 a를 의미한다.
/// DFS를 이용해 4방향으로 이동한다.
/// 이동하면서 현재 지점보다 낮은 지점으로만 가면서 dp를 채워간다.
/// </summary>

int M = 0, N = 0; //세로의 크기 M, 가로의 크기 N

int map[500][500];
int dp[500][500];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


int DFS(int x, int y)
{
	if (x == N - 1 && y == M - 1)
		return 1;
	if (dp[y][x] != -1)
		return dp[y][x];

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) 
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && 0 <= ny && nx < N && ny < M)
		{
			if (map[ny][nx] < map[y][x])
			{
				dp[y][x] = dp[y][x] + DFS(nx, ny);
			}
		}
	}
	return dp[y][x];
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
			dp[i][j] = -1;
		}
	}

	int result = DFS(0, 0);
	cout << result << "\n";

	return 0;
}