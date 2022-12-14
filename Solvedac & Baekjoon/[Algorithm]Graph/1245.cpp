#include<iostream>
#include<vector>
#include<queue>

#define MAX_DISTANCE 987654321 //int���� �ִ�
using namespace std;

/// <summary>
/// Gold5 - Graph �˰���
/// ���� ���� �ִ� ������ ������ ���� ���̰� ũ�ٸ� ������� �ƴϴ�
/// �׷��Ƿ� BFS�����, ���̰� ���� ���� ���ؼ��� BFS�� �����Ų��
/// vector�� �޸� ȿ���� ������ �⺻������ ��ƸԴ� �޸𸮰� ����
/// �׷��ٺ��� �޸� �ʰ� ������ �ߴ� �׳� �迭�� ��������
/// </summary>

int n, m; //n��, m���� �����ִ� ��������

//���� ���� �����ʺ��� 8�� �� ����
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool IsPeak = true; //����������

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
				//�� ���� ������� ã�Ҵٸ�
				IsPeak = false;
			}
			if (visited[nextY][nextX] || matrix[y][x] != matrix[nextY][nextX])
			{
				//���̰� ���� ������� Ž���ϱ�
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