#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ü���� �ٽ� ĥ�ϱ� - ���Ʈ���� �˰���
/// N-8�� M-8�� ������ ���带 �߶� 8*8�� ������� �ϸ�, �̶� �� ĭ �ϳ��ϳ��� �����ؼ� �����ϱ� �����̴�
/// White�� 0���� Black�� 1�� intŸ������ �ٲ� ���忡 ���
/// </summary>

using namespace std;

int N(0), M(0); //M*N ũ���� ����
vector<vector<int>> board(51, vector<int>(51, 0));

int BoardCheck(int x, int y)
{
	int drawWhite(0), drawBlack(0);

	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j < x + 8; j++)
		{
			if ((i + j) % 2 == board[i][j])
			{
				//Ž�� �����ϴ� ù ���� ����ΰ��
				drawWhite++;
			}
			if ((i + j + 1) % 2 == board[i][j])
			{
				//Ž�� �����ϴ� ù ���� �������� ���
				drawBlack++;
			}
		}
	}
	int result = std::min(drawWhite, drawBlack);
	return result;
}

int main(void)
{
	FastIO;

	int drawMinCnt(2500); //M�� N�� �ִ밡 50���� 50*50=2500

	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char input;
			std::cin >> input;
			if (input == 'W')
			{
				board[i][j] = 0;
			}
			else
			{
				board[i][j] = 1;
			}
		}
	}

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			drawMinCnt = std::min(drawMinCnt, BoardCheck(j, i));
		}
	}

	std::cout << drawMinCnt << "\n";

	return 0;
}