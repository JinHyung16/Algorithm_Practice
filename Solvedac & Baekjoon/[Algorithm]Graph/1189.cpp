#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver1 컴백홈 - Garph 알고리즘
/// DFS를 이용해 다 방문해보자!
/// 상하좌우 움직일 땐, dr과 dc 선언한걸 기준으로 0~4까지 돌려서 방문하게 하자
/// 크기가 크지 않으므로 재귀적으로 풀자
/// </summary>

vector<vector<char>> map(5, vector<char>(5, ' '));
vector<vector<bool>> visited(5, vector<bool>(5, false));
vector<int> dr = { 0, 0, 1, -1 };
vector<int> dc = { -1, 1, 0, 0 };

int r, c, k(0);

int DFS(int row, int col, int dis)
{
	if (dis == k)
	{
		return map[row][col] == 'H' ? 1 : 0;
	}

	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		int nextR = row + dr[i];
		int nextC = col + dc[i];

		if (0 <= nextR && nextR < r && 0 <= nextC && nextC < c) 
		{
			if (nextR < 0 || r <= nextR || nextC < 0 || c <= nextC || map[nextR][nextC] == 'T' || visited[nextR][nextC])
			{
				continue;
			}
			visited[nextR][nextC] = true;
			count += DFS(nextR, nextC, dis + 1);
			visited[nextR][nextC] = false;
		}
	}

	return count;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> r >> c >> k;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cin >> map[i][j];
		}
	}

	visited[r - 1][0] = true;
	map[0][c - 1] = 'H'; //맵의 우측 상단은 home이니 미리 정하고 시작

	int result = DFS(r - 1, 0, 1);
	std::cout << result << std::endl;

	return 0;
}