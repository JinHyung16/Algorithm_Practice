#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���� ���� - Graph �˰���
/// �������� �ƹ� ������ ���� ����� ���� �� �ִٰ� �߱⿡, ���� 1���� 100���� �� �����Ѵ�.
/// </summary>

using namespace std;

int N(0); //��� ���� ���� N, �帶ö �� ���� N
vector<vector<int>> regions(101, vector<int>(101, 0));
vector<vector<bool>> visited(101, vector<bool>(101, false));
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Reset()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			visited[i][j] = false;
		}
	}
}
void BFS(int x, int y, int h)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[y][x] = true;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = dx[i] + curX;
			int nextY = dy[i] + curY;

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N && !visited[nextY][nextX] && h < regions[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				q.push(make_pair(nextX, nextY));
			}
		}
	}
}

int main(void)
{
	FastIO;
	
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> regions[i][j];
		}
	}

	int maxSafeReionCnt = 1;
	for (int h = 1; h <= 100; h++)
	{
		int safeRegionCnt = 0;
		Reset();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j] && h < regions[i][j])
				{
					BFS(j, i, h);
					safeRegionCnt++;
				}
			}
		}
		
		if (safeRegionCnt == 0)
		{
			break;
		}

		if (maxSafeReionCnt < safeRegionCnt)
		{
			maxSafeReionCnt = safeRegionCnt;
		}
	}

	std::cout << maxSafeReionCnt << "\n";
	return 0;
}