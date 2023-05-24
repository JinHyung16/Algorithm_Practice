#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 나이트의 이동 - Graph 알고리즘
/// 나이트의 경우 본인 기준 2번의 걸쳐 움직인다.
/// 1차는 본인기준 상하좌우, 2차는 1차에서 대각선 방향.
/// 이를 종합해보면 나이트는 본인 기준 8방향으로 움직이며
/// 본인 기준 상하좌우로 2칸가고 거기서 좌우/상하로 1칸 움직이면 된다.
/// board에 움직인 횟수를 저장해가며 다음 움직인 횟수는 이전 움직인 횟수에서 + 1 해간다.
/// </summary>

using namespace std;

vector<vector<int>> board(301, vector<int>(301, 0));
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void BFS(int sx, int sy, int ex, int ey, int l)
{
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));

	board[sy][sx] = 1;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		if (curX == ex && curY == ey)
		{
			break;
		}

		for (int i = 0; i < 8; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			
			if (0 <= nextX && nextX < l && 0 <= nextY && nextY < l && board[nextY][nextX] == 0)
			{
				board[nextY][nextX] = board[curY][curX] + 1;
				q.push(make_pair(nextX, nextY));
			}
		}
	}
}

int main(void)
{
	FastIO;
	
	int T(0); //테스트 케이스의 개수
	int L(0); //체스판 한 변의 길이
	int startX(0), startY(0), endX(0), endY(0); //나이트의 시작 지점과 도착지점
	std::cin >> T;
	while (T--)
	{
		std::cin >> L;
		std::cin >> startX >> startY;
		std::cin >> endX >> endY;
		BFS(startX, startY, endX, endY, L);
		std::cout << board[endY][endX] - 1 << "\n";
		for (int i = 0; i < 300; i++)
		{
			for (int j = 0; j < 301; j++)
			{
				board[i][j] = 0;
			}
		}
	}
	return 0;
}