#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 �� ��� 11 - ��� �˰���
/// N�� 3*2^k�� ǥ���ȴ�. ���� 3�� ����� ���� �ﰢ���� �׷������� �ȴ�.
/// �迭�� ������ ���ø� ���� 24�϶� ���ΰ� 47�� �� 2������ ���̳��Ƿ�, 2���� �迭�� �����Ѵ�.
/// N�� 3�� �ɶ�, �� �� �ﰢ���� �׷��� �ϹǷ�, �Ʒ��� �ٸ� �������� �׷����Ѵ�. ���� �̶� �ﰢ�� �׸��� ��͸� ������.
/// n==3�� ��ü ū �ﰢ������ ���� �ﰢ���� �ٽ� ���� �ﰢ����� ������ ��, �� �ﰢ���� �ǹ��Ѵ�.
/// �̸� �ﰢ�� ������ �����Ͽ� ���Ѵ�.
/// </summary>

using namespace std;

vector<vector<char>> map(3100, vector<char>(6200, ' '));

void DrawStar(int x, int y, int n)
{
	if (n == 3)
	{
		map[y][x] = '*';
		map[y + 1][x - 1] = '*';
		map[y + 1][x + 1] = '*';
		for (int i = x - 2; i <= x + 2; i++)
		{
			map[y + 2][i] = '*';
		}
		return;
	}

	DrawStar(x, y, (n / 2));
	DrawStar(x - (n / 2), y + (n / 2), (n / 2));
	DrawStar(x + (n / 2), y + (n / 2), (n / 2));
}

int main(void)
{
	FastIO;
	
	int N(0);
	std::cin >> N;
	
	DrawStar(N - 1, 0, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N - 1; j++)
		{
			if (map[i][j] == '*')
			{
				std::cout << map[i][j];
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
	return 0;
}