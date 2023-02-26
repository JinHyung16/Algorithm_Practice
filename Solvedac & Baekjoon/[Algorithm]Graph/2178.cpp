#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 미로 탐색 - Graph 알고리즘
/// 붙어서 입력 받으니, string아니면 char로 입력받자!
/// BFS를 이용하여 해결
/// </summary>

using namespace std;

int N(0), M(0); //N*M 크기의 미로, N개의 줄의 M개의 정수로 이뤄진 미로
vector<vector<int>> miro(101, vector<int>(101, 0));
vector<vector<int>> recordDistance(101, vector<int>(101, 0));
vector<vector<bool>> visited(101, vector<bool>(101, false));

int dx[4] = { -1, 1, 0, 0 }; //좌우 움직일 방향
int dy[4] = { 0, 0, 1, -1 }; //상하 움직일 방향

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	visited[y][x] = true;
	recordDistance[y][x] += 1;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N)
			{
				if (!visited[nextY][nextX] && miro[nextY][nextX] == 1)
				{
					q.push({ nextX, nextY });
					recordDistance[nextY][nextX] = (recordDistance[curY][curX] + 1);
					visited[nextY][nextX] = true;
				}
			}
		}
	}
}
int main(void)
{
	FastIO;
	
	std::cin >> N >> M;

	for (int row = 0; row < N; row++)
	{
		string input;
		std::cin >> input;
		for (int col = 0; col < M; col++)
		{
			miro[row][col] = input[col] - '0';
		}
	}
	
	BFS(0, 0);
	
	std::cout << recordDistance[N - 1][M - 1] << "\n";
	return 0;
}