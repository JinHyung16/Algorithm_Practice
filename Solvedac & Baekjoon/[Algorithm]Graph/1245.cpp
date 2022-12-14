#include<iostream>
#include<vector>
#include<queue>

#define MAX_DISTANCE 987654321 //int형의 최댓값
using namespace std;

/// <summary>
/// Gold5 - Graph 알고리즘
/// 현재 내가 있는 곳보다 인접한 곳의 높이가 크다면 산봉오리 아니다
/// 그러므로 BFS진행시, 높이가 같은 곳에 대해서만 BFS를 진행시킨다
/// vector가 메모리 효율은 좋으나 기본적으로 잡아먹는 메모리가 높다
/// 그러다보니 메모리 초과 오류가 뜨니 그냥 배열로 변경하자
/// </summary>

int n, m; //n줄, m개의 높이있는 봉오리들

//본인 기준 오른쪽부터 8곳 다 보기
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool IsPeak = true; //봉오리인지

int matrix[101][71];
bool visited[101][71] = { false, };

void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[y][x] = true;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();
		
		for (int i = 0; i < 8; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (nextX < 0 || m <= nextX || nextY < 0 || n <= nextY)
			{
				continue;
			}
			if (matrix[y][x] < matrix[nextY][nextX])
			{
				//더 높은 산봉오리 찾았다면
				IsPeak = false;
			}
			if (visited[nextY][nextX] || matrix[y][x] != matrix[nextY][nextX])
			{
				//높이가 같은 산봉오리 탐색하기
				continue;
			}
			q.push({ nextX, nextY });
			visited[nextY][nextX] = true;
		}
	}

}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int index;
		for (int j = 0; j < m; j++)
		{
			std::cin >> index;
			matrix[i][j] = index;
		}
	}

	int peakCount = 0;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (!visited[y][x])
			{
				IsPeak = true;
				BFS(y, x);
				if (IsPeak)
				{
					peakCount++;
				}
			}
		}
	}

	std::cout << peakCount << std::endl;
	return 0;
}