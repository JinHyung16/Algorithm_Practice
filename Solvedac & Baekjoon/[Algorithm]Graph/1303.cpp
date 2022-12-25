#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver1 ����-���� - Graph �˰���
/// BFS�� �̿��� �� �� ���忡�� �����Ѵ�.
/// �̶� �߰��� �� ��ü�� �� �ʱ�ȭ �ϴ°� ��������
/// ���� �ʿ��� x�� �𿩾� �ϳ��� y�� �����ϴ� �迭 index ������ x y ���� �߿�
/// BFS �Ķ���Ͱ� x,y���ε� ���� for���� ������ x�̹Ƿ� index�� �����ؼ� ����!
/// �ʱ�ȭ�� memset�̳� fill(fill_n)����ص� ������
/// ���� vector�� ����ؼ� �׳� for���� ���� ���� �ߴ�.
/// </summary>

using namespace std;

const int MAX_VAlUE = 101;
int W(0), H(0); //���� ũ�� N, ���� ũ�� M �ǹ�
vector<vector<char>> charMap(MAX_VAlUE, vector<char>(MAX_VAlUE, ' '));
vector<vector<int>> intMap(MAX_VAlUE, vector<int>(MAX_VAlUE, 0));
vector<vector<bool>> visitedMap(MAX_VAlUE, vector<bool>(MAX_VAlUE, false));
vector<int> dx = { 0, 0, -1, 1 };
vector<int> dy = { 1, -1, 0, 0 };

int whiteSoldiers = 0;
int blueSoldiers = 0;
int soldier = 1;


void ResetMap()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			intMap[i][j] = 0;
			visitedMap[i][j] = false;
		}
	}
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	visitedMap[y][x] = true;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (nextX < 0 || nextX >= W || nextY < 0 || nextY >= H)
			{
				continue;
			}
			if (intMap[nextY][nextX] == 1 && !visitedMap[nextY][nextX])
			{
				visitedMap[nextY][nextX] = true;
				soldier++;
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

	std::cin >> W >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			std::cin >> charMap[i][j];
		}
	}

	//White ���� ������ �����ϱ�
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (charMap[i][j] == 'W')
			{
				intMap[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (intMap[i][j] == 1 && !visitedMap[i][j])
			{
				BFS(j, i); //x,y������ �־���Ѵ�
				whiteSoldiers += soldier * soldier;
				soldier = 1;
			}
		}
	}

	//�� �ʱ�ȭ �ϱ�
	ResetMap();

	//Blue ���� ������ �����ϱ�
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (charMap[i][j] == 'B')
			{
				intMap[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (intMap[i][j] == 1 && !visitedMap[i][j])
			{
				BFS(j, i); //x,y������ �־���Ѵ�
				blueSoldiers += soldier * soldier;
				soldier = 1;
			}
		}
	}

	std::cout << whiteSoldiers << " " << blueSoldiers << std::endl;
	return 0;
}