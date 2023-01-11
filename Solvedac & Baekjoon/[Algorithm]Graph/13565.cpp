#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 침투 - Graph 알고리즘
/// BFS를 이용한 문제 풀이
/// 미로 탈출과 비슷하다고 생각해보자
/// 주의할게 공백없이 미로를 받기에 그냥 cin으로 받으면 안된다.
/// scanf("%1d", &map[i][j]); 또는 char input에 std::cin >> input후 input -'0' 해주자
/// </summary>

using namespace std;

int M(0), N(0); //격자 크기 M*N == Y*X의 의미

vector<vector<int>> map(1001, vector<int>(1001, 0));
vector<vector<bool>> visited(1001, vector<bool>(1001, false));

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void BFS(int x, int y)
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
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (nextX < 0 || N <= nextX || nextY < 0 || M <= nextY)
			{
				continue;
			}

			if (map[nextY][nextX] == 0 && !visited[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				q.push({ nextX, nextY });
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		char input;
		for (int j = 0; j < N; j++)
		{
			std::cin >> input;
			map[i][j] = input - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (map[0][i] == 0 && !visited[0][i])
		{
			BFS(i, 0); //(x,y) 순으로 넣어야 한다.
		}
	}

	bool IsCorrect = false; //전류가 흐르는지 체크하는 flag
	for (int i = 0; i < N; i++)
	{
		if (visited[M - 1][i])
		{
			IsCorrect = true;
		}
	}

	if (IsCorrect)
	{
		std::cout << "YES" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}

	return 0;
}