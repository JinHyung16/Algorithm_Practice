#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 �丶�� - �׷��� �˰���
/// 3���� ���͸� �����Ͽ� �ذ��Ѵ�. ���� 2���� BFS���� ���̰� �߰��Ǿ��� �����Ѵ�. �̶� ���̸� h�Ǵ� z�� �θ���
/// 1. ���� �Է¹����鼭 �丶�䰡 �ִ� ��ġ���� queue�� ��Ƶд�. �̶� x,y,z������ push
/// 2. x, y, z�࿡ ���� �̵������ϰ� dx, dy, dz�迭�� �����.
/// 3. queue�� ���鼭 �ش� ��ġ���� z�����, y�����, x��������� BFS�� �����Ѵ�. �׷��鼭 ripenDay�� ������Ų��.
/// 4. �丶�䰡 �ִ� ��� ������ Ž���� ����ٸ�, ��ü �丶�䰡 �ɾ��� ���ڸ� ���鼭 �ϳ��� 0�� �κ��� �ִ��� Ȯ���Ѵ�.
/// 5. �ִٸ� -1�� return ���ٸ� ripenDay�� ��ȯ�Ѵ�.
/// �̶� ripenDay�� �丶�� Ž���� while������ �������� q ����� q�� null�� ���¿��� �ѹ� �� �����ϰ� ���� ���߱⿡ -1�� ���ش�.
/// </summary>

using namespace std;

int M(0), N(0), H(0); //���� M, ���� N, �׾� �÷����� ���� �� H
vector<vector<vector<int>>> tomato(102, vector<vector<int>>(102, vector<int>(102)));
queue<pair<pair<int, int>, int>> q; //���� �丶�並 ��Ƴ��´�.

//����, ����, �¿� ������ ��´�
int dx[6] = { 0, 0, 1, 0, 0, -1 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 1, 0, 0, -1, 0, 0 };

int BFS()
{
	int ripenDay = 0;
	while (!q.empty())
	{
		int qSize = q.size();
		ripenDay++;

		for (int i = 0; i < qSize; i++)
		{
			int curX = q.front().first.first;
			int curY = q.front().first.second;
			int curZ = q.front().second;
			q.pop();

			for (int j = 0; j < 6; j++)
			{
				int nextX = curX + dx[j];
				int nextY = curY + dy[j];
				int nextZ = curZ + dz[j];

				if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N && 0 <= nextZ && nextZ < H
					&& tomato[nextZ][nextY][nextX] == 0)
				{
					q.push({ { nextX, nextY }, nextZ });
					tomato[nextZ][nextY][nextX] = 1;
				}
			}
		}
	}

	//���� ���� �丶�䰡 �ִ��� Ȯ��
	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (tomato[h][i][j] == 0)
				{
					return -1;
				}
			}
		}
	}

	return (ripenDay - 1);
}

int main(void)
{
	FastIO;

	std::cin >> M >> N >> H;

	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				std::cin >> tomato[h][i][j];
				if (tomato[h][i][j] == 1)
				{
					q.push({ {j,i},h });
				}
			}
		}
	}

	int result = BFS();
	std::cout << result << "\n";
	return 0;
}