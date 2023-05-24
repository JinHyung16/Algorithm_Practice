#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ����Ʈ�� �̵� - Graph �˰���
/// ����Ʈ�� ��� ���� ���� 2���� ���� �����δ�.
/// 1���� ���α��� �����¿�, 2���� 1������ �밢�� ����.
/// �̸� �����غ��� ����Ʈ�� ���� ���� 8�������� �����̸�
/// ���� ���� �����¿�� 2ĭ���� �ű⼭ �¿�/���Ϸ� 1ĭ �����̸� �ȴ�.
/// board�� ������ Ƚ���� �����ذ��� ���� ������ Ƚ���� ���� ������ Ƚ������ + 1 �ذ���.
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
	
	int T(0); //�׽�Ʈ ���̽��� ����
	int L(0); //ü���� �� ���� ����
	int startX(0), startY(0), endX(0), endY(0); //����Ʈ�� ���� ������ ��������
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