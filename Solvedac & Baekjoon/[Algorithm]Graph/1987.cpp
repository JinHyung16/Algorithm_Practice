#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 알파벳 - Graph 알고리즘
/// DFS를 이용한 풀이다.
/// 1) 갈 수 있는 방향으로 더이상 진행이 불가능 할 때까지 가면서 최대 move cnt를 기록해둔다.
/// 2) 더이상 갈 수 없으면 back tracking하여 뒤로 돌아오고 move cnt값을 항상 최대 값으로 갱신한다.
/// visited는 알파벳 개수만큼 있어서 이미 방문했던 알파벳 index가 true인지 확인할 때 쓴다.
/// </summary>

using namespace std;

vector<vector<char>> board(21, vector<char>(21, ' '));
vector<bool> visited(26, false);

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int maxMoveCnt = 1;

void DFS(int x, int y, int r, int c, int moveCnt)
{
	if (maxMoveCnt < moveCnt)
	{
		maxMoveCnt = moveCnt;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (0 <= nextX && nextX < c && 0 <= nextY && nextY < r && !visited[board[nextY][nextX] - 'A'])
		{
			visited[board[nextY][nextX] - 'A'] = true; //방문했다고 체크하고
			DFS(nextX, nextY, r, c, moveCnt + 1); //DFS를 재귀호출 한다.
			visited[board[nextY][nextX] - 'A'] = false; //그리고 나서 지금 방문함 지점을 false로 해서 마치 back tracking 한 것처럼 한다.
		}
	}

}

int main(void)
{
	FastIO;

	int R(0), C(0); //세로 R, 가로 C
	std::cin >> R >> C;

	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			std::cin >> board[i][j];
		}
	}
	visited[board[0][0] - 'A'] = true;
	DFS(0, 0, R, C, 1);
	std::cout << maxMoveCnt << "\n";
	return 0;
}
