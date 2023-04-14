#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 ���ϻ��� - �׷��� �˰���
/// BFS�� ���鼭 R, G, B�� ���ؼ� ������ ã�ƾ��Ѵ�.
/// ������� ù ������ R�̸� ���� G�� B�� ������ ������ ���� �������� BFS�� ���ϱ� ī��Ʈ�� �����Ǵٰ�
/// G�� B�� ������ ī��Ʈ�� ���� ��Ų��. �̷��� ���� for������ BFS�� ȣ�� �Ǵ� Ƚ���� �� ī��Ʈ����.
/// ��� ���ϻ����� ����� G==R�̹Ƿ�, G�� R�� �ٲٰų� R�� G�� �ٲ� �ΰ��� ���� ���� �ذ��Ѵ�.
/// </summary>

using namespace std;

int N(0); //ũ�Ⱑ N*N�� �׸���
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