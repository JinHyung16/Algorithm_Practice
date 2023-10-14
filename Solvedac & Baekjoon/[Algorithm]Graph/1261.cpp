#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold4 알고스팟 - Graph 알고리즘
/// 다익스트라로 문제를 해결한다.
/// 최소로 벽을 뚫어야하니 벽을 가중치라 가정
/// dist 배열의 가중치를 저장한다.
/// </summary>

int board[101][101];
int dist[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void BFS(int m, int n)
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dist[0][0] = 0;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (nextX < 0 || nextY < 0 || m <= nextX || n <= nextY)
			{
				continue;
			}
			if (board[nextY][nextX] == 1)
			{
				if (dist[curY][curX] + 1 < dist[nextY][nextX])
				{
					dist[nextY][nextX] = dist[curY][curX] + 1;
					q.push(make_pair(nextX, nextY));
				}
			}
			else if (board[nextY][nextX] == 0)
			{
				if (dist[curY][curX] < dist[nextY][nextX])
				{
					dist[nextY][nextX] = dist[curY][curX];
					q.push(make_pair(nextX, nextY));
				}
			}
		}
	}
}

int main(void)
{
	FastIO;

	int N = 0, M = 0; //가로 크기 M, 세로 크기 N
	cin >> M >> N;
	string input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = input[j] - '0';
			dist[i][j] = 987654321;
		}
	}

	BFS(M, N);
	cout << dist[N - 1][M - 1] << "\n";
	return 0;
}