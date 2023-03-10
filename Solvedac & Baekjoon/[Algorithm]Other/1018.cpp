#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 체스판 다시 칠하기 - 브루트포스 알고리즘
/// N-8과 M-8인 이유는 보드를 잘라서 8*8로 만드려고 하며, 이때 각 칸 하나하나를 전달해서 봐야하기 때문이다
/// White는 0으로 Black은 1로 int타입으로 바꿔 보드에 기록
/// </summary>

using namespace std;

int N(0), M(0); //M*N 크기의 보드
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
				//탐색 시작하는 첫 블럭이 흰색인경우
				drawWhite++;
			}
			if ((i + j + 1) % 2 == board[i][j])
			{
				//탐색 시작하는 첫 블럭이 검은색인 경우
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

	int drawMinCnt(2500); //M과 N의 최대가 50으로 50*50=2500

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