#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 ���ĺ� - Graph �˰���
/// DFS�� �̿��� Ǯ�̴�.
/// 1) �� �� �ִ� �������� ���̻� ������ �Ұ��� �� ������ ���鼭 �ִ� move cnt�� ����صд�.
/// 2) ���̻� �� �� ������ back tracking�Ͽ� �ڷ� ���ƿ��� move cnt���� �׻� �ִ� ������ �����Ѵ�.
/// visited�� ���ĺ� ������ŭ �־ �̹� �湮�ߴ� ���ĺ� index�� true���� Ȯ���� �� ����.
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
			visited[board[nextY][nextX] - 'A'] = true; //�湮�ߴٰ� üũ�ϰ�
			DFS(nextX, nextY, r, c, moveCnt + 1); //DFS�� ���ȣ�� �Ѵ�.
			visited[board[nextY][nextX] - 'A'] = false; //�׸��� ���� ���� �湮�� ������ false�� �ؼ� ��ġ back tracking �� ��ó�� �Ѵ�.
		}
	}

}

int main(void)
{
	FastIO;

	int R(0), C(0); //���� R, ���� C
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
