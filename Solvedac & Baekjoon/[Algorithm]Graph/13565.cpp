#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 ħ�� - Graph �˰���
/// BFS�� �̿��� ���� Ǯ��
/// �̷� Ż��� ����ϴٰ� �����غ���
/// �����Ұ� ������� �̷θ� �ޱ⿡ �׳� cin���� ������ �ȵȴ�.
/// scanf("%1d", &map[i][j]); �Ǵ� char input�� std::cin >> input�� input -'0' ������
/// </summary>

using namespace std;

int M(0), N(0); //���� ũ�� M*N == Y*X�� �ǹ�

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
			BFS(i, 0); //(x,y) ������ �־�� �Ѵ�.
		}
	}

	bool IsCorrect = false; //������ �帣���� üũ�ϴ� flag
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