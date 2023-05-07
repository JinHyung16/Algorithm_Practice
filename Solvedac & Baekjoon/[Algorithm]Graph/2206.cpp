#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 �� �μ��� �̵��ϱ� - Graph �˰���
/// BFS�� �̿��� �ذ��Ѵ�.
/// ���� �μ��°� �ֱ⿡, queue�� ���� �μ̴����� ���� ���α��� �����صд�.
/// 
/// visited���� �湮�� ������ ���� ���� �μ� ���¿�, ���� �μ��� ���� ���º��� �̵��� ĭ�� ������ �����Ѵ�.
/// visited[y][x][0]�� ���� �μ� ���¿��� �ش� ĭ�� �����ϴ� ���� �̵��� ĭ�� ����
/// visited[y][x][1]�� ���� �μ��� ���� ���¿��� �ش� ĭ�� �����ϴ� ���� �̵��� ĭ�� ����
/// </summary>

using namespace std;

int N(0), M(0); //N*M ���� ���

vector<vector<int>> map(1000, vector<int>(1000, 0));
int visited[1000][1000][2];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int BFS(int x, int y)
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));
	visited[y][x][1] = 1;
	
	while (!q.empty())
	{
		int curX = q.front().first.second;
		int curY = q.front().first.first;
		int block = q.front().second; //1�� ����
		q.pop();

		if (curX == M - 1 && curY == N - 1)
		{
			return visited[curY][curX][block];
		}

		for (int i = 0; i < 4; i++)
		{
			int nextX = dx[i] + curX;
			int nextY = dy[i] + curY;
			if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N)
			{
				//���� ĭ�� ���̰�, ���� �� ���� ��
				if (map[nextY][nextX] == 1 && block)
				{
					q.push(make_pair(make_pair(nextY, nextX), 0));
					visited[nextY][nextX][block - 1] = visited[curY][curX][block] + 1;
				}
				//���� ĭ�� ���� �ƴϰ�, ���� �湮������ ���ٸ�
				else if (map[nextY][nextX] == 0 && visited[nextY][nextX][block] == 0)
				{
					q.push(make_pair(make_pair(nextY, nextX), block));
					visited[nextY][nextX][block] = visited[curY][curX][block] + 1;
				}
			}
		}
	}

	return -1;
}

int main(void)
{
	FastIO;

	std::cin >> N >> M;
	char input(' ');
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> input;
			map[i][j] = input - '0';
		}
	}

	int result = BFS(0, 0);
	std::cout << result << "\n";
	return 0;
}