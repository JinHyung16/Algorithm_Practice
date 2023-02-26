#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 �̷� Ž�� - Graph �˰���
/// �پ �Է� ������, string�ƴϸ� char�� �Է¹���!
/// BFS�� �̿��Ͽ� �ذ�
/// </summary>

using namespace std;

int N(0), M(0); //N*M ũ���� �̷�, N���� ���� M���� ������ �̷��� �̷�
vector<vector<int>> miro(101, vector<int>(101, 0));
vector<vector<int>> recordDistance(101, vector<int>(101, 0));
vector<vector<bool>> visited(101, vector<bool>(101, false));

int dx[4] = { -1, 1, 0, 0 }; //�¿� ������ ����
int dy[4] = { 0, 0, 1, -1 }; //���� ������ ����

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