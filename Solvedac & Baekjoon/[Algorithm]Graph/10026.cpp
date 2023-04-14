#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 적록색약 - 그래프 알고리즘
/// BFS를 돌면서 R, G, B에 대해서 구역을 찾아야한다.
/// 예를들어 첫 시작이 R이면 다음 G나 B가 나오기 전까진 같은 구역으로 BFS를 도니깐 카운트가 유지되다가
/// G나 B가 나오면 카운트를 증가 시킨다. 이렇게 이중 for문에서 BFS가 호출 되는 횟수가 즉 카운트수다.
/// 대신 적록색약인 사람은 G==R이므로, G를 R로 바꾸거나 R을 G로 바꿔 두개를 같다 놓고 해결한다.
/// </summary>

using namespace std;

int N(0); //크기가 N*N인 그리드
vector<vector<char>> paint(101, vector<char>(101, ' '));
vector<vector<bool>> visited(101, vector<bool>(101, false));
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
void ResetVector()
{
	for (int i = 0; i < visited.size(); i++)
	{
		for (int j = 0; j < visited.size(); j++)
		{
			visited[i][j] = false;
		}
	}
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
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

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N) 
			{
				if (!visited[nextY][nextX] && paint[nextY][nextX] == paint[curY][curX])
				{
					q.push({ nextX, nextY });
					visited[nextY][nextX] = true;
				}
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
			std::cin >> paint[i][j];
		}
	}

	int rgCnt(0), rgweaknessCnt(0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				BFS(j, i);
				rgCnt++;
			}
		}
	}

	ResetVector();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)		
		{
			if (paint[i][j] == 'G')
			{
				paint[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				BFS(j, i);
				rgweaknessCnt++;
			}
		}
	}

	std::cout << rgCnt << " " << rgweaknessCnt << "\n";
	return 0;
}