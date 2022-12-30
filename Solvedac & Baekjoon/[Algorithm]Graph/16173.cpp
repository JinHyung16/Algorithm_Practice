#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver4 ������ �f��(Small) - Graph �˰���
/// BFS�� �̿��� Ǯ��
/// �׻� 2���� �迭���� ����(x)�� �𿩾� �ϳ��� ����(y)�� �ǹǷ� �迭 �ε����� ������!
/// ���� BFS���� �����̴� ���⸸ŭ �����̴µ� ���⿡ map�� ���� ���ڸ�ŭ �����̴� * ������
/// </summary>

using namespace std;

int N(0); //���� ������ ũ�� N
vector<vector<int>> map(3, vector<int>(3, 0)); //N�� �ִ� ������ 3�̱� ����
vector<vector<bool>> visited(3, vector<bool>(3, false)); //�湮�ߴ��� üũ

//x�� y������ �̵��ϴ� ������ �ǹ��ϴµ� �Ʒ��� ���������θ� �̵� �����ϴ�
vector<int> dx = { 0, 1 };
vector<int> dy = { 1, 0 };

bool BFS()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0)); //x y ��ǥ ������ ����

	visited[0][0] = true;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		if (map[curY][curX] == -1)
		{
			//�������� ���޽� ���� ��
			return true;
		}

		for (int i = 0; i < 2; i++)
		{
			int nextX = curX + dx[i] * map[curY][curX];
			int nextY = curY + dy[i] * map[curY][curX];

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
			{
				//������ �� ���� �ִ°��
				if (!visited[nextY][nextX])
				{
					//�湮�� ���� ���ٸ� �湮
					visited[nextY][nextX] = true;
					q.push({ nextX, nextY });
				}
			}
		}
	}

	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
		}
	}

	if (BFS())
	{
		std::cout << "HaruHaru" << std::endl;
	}
	else
	{
		std::cout << "Hing" << std::endl;
	}

	return 0;
}