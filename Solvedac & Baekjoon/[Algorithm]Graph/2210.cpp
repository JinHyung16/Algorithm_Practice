#include<iostream>
#include<vector>
#include<algorithm>

/// <summary>
/// Silver2 ������ ���� - Graph �˰���
/// DFS�� �⺻ ��͸� ���� �ʿ�
/// �ߺ��� ���ڸ� �����ϴ� ������ �ʿ��ϴ�
/// sort�� �̿��� ������ �� unique�� ���� �ߺ����� �ʴ� ���ҵ��� ä���� ��
/// erase�� ���� ������ �Ѵ�.
/// *�ƴϸ� set�� ����� ó������ �ߺ��� ������ �� �ִ�.
/// </summary>

using namespace std;

const int N = 5; //�� size N*N �ǹ�, �ִ� ������ 5

vector<vector<int>> map(N, vector<int>(N, 0));
vector<int> digits; //���� �����ؼ� 6�ڸ��� �Ǵ��� �˻�

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void DFS(int x, int y, int num, int length)
{
	if (length == 6)
	{
		digits.push_back(num);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
		{
			DFS(nextX, nextY, (num * 10 + map[nextY][nextX]), length + 1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			DFS(j, i, map[i][j], 1); //(x,y), length ������ �ִ´�
		}
	}

	std::sort(digits.begin(), digits.end());
	digits.erase(unique(digits.begin(), digits.end()), digits.end());

	std::cout << digits.size() << std::endl;
	return 0;
}