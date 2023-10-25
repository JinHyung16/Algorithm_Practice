#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 미로 탐색 - Graph 알고리즘
/// BFS를 통해 문제를 해결한다.
/// </summary>

int N = 0, M = 0; //행N, 열M개
vector<vector<int>> miro; 
vector<vector<int>> dist;
vector<vector<bool>> visited;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[y][x] = true;
	dist[y][x] = 1;

	while ( !q.empty() )
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for ( int i = 0; i < 4; i++ )
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if ( nextX < 0 || nextY < 0 || N <= nextY || M <= nextX )
				continue;

			if ( !visited[nextY][nextX] && miro[nextY][nextX] == 1)
			{
				visited[nextY][nextX] = true;
				q.push(make_pair(nextX, nextY));
				dist[nextY][nextX] = dist[curY][curX] + 1;
			}
		}
	}
}

int main(void)
{
	FastIO;

	cin >> N >> M;
	miro.resize(N + 1, vector<int>(M + 1, -1));
	dist.resize(N + 1, vector<int>(M + 1, 0));
	visited.resize(N + 1, vector<bool>(M + 1, false));

	for ( int i = 0; i < N; i++ )
	{
		string input;
		cin >> input;
		for ( int j = 0; j < M; j++ )
		{
			miro[i][j] = input[j] - '0';
		}
	}

	BFS(0, 0);

	cout << dist[N - 1][M - 1] << "\n";
	return 0;
}