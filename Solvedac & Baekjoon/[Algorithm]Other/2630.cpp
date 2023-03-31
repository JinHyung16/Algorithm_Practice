#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 색종이 만들기 - 분할 정복 알고리즘
/// 색이 같지 않으면 1사분면, 2사분면, 3사분면, 4사분면으로 나눠 계속돈다.
/// 이때 각 사분면의 시작 좌표는 길이/2 씩 더해서 보낸다.
/// 각 사분면의 색을 체크하는 순간은 재귀 호출이 안됐을때 체크해야한다.
/// </summary>

using namespace std;

int whiteRegion(0), blueRegion(0);
vector<vector<int>> paper(129, vector<int>(129, 0)); //N의 최대가 2^7이므로

void CheckRegion(int x, int y, int len)
{
	int curColor = paper[y][x];
	for (int i = y; i < y + len; i++)
	{
		for (int j = x; j < x + len; j++)
		{
			if (curColor != paper[i][j])
			{
				CheckRegion(x, y, len / 2);
				CheckRegion(x + (len / 2), y, len / 2);
				CheckRegion(x, y + (len / 2), len / 2);
				CheckRegion(x + (len / 2), y + (len / 2), len / 2);
				return;
			}
		}
	}

	//재귀 호출시 for문안에서 증가시키면 값이 더 늘어나기에 재귀 호출이 안된경우만 체크해야한다.
	if (curColor == 1)
	{
		blueRegion += 1;
	}
	else
	{
		whiteRegion += 1;
	}
}

int main(void)
{
	FastIO;

	int  N(0); //종이의 사이즈 N
	std::cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> paper[i][j];
		}
	}

	CheckRegion(0, 0, N);
	std::cout << whiteRegion << "\n" << blueRegion << "\n";

	return 0;
}