#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 별 찍기 11 - 재귀 알고리즘
/// N은 3*2^k로 표현된다. 따라서 3의 배수에 맞춰 삼각형을 그려나가면 된다.
/// 배열의 범위는 예시를 보면 24일때 가로가 47로 약 2배정도 차이나므로, 2차원 배열을 생성한다.
/// N이 3이 될때, 맨 위 삼각형을 그려야 하므로, 아래와 다른 형식으로 그려야한다. 따라서 이때 삼각형 그리고 재귀를 끝낸다.
/// n==3은 전체 큰 삼각형으로 나눈 삼각형을 다시 작은 삼각형들로 나눴을 때, 각 삼각형을 의미한다.
/// 이를 삼각형 단위로 분할하여 구한다.
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