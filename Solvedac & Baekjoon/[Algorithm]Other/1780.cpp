#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 종이의 개수 - 분할 정복 알고리즘
/// N은 3의 제곱수 크기 사이다. 따라서 분할시 /3으로 구역을 나눠야한다.
/// N의 최대는 3^7으로 2183이다.
/// </summary>

using namespace std;

vector<vector<int>> paper(2200, vector<int>(2200, 0));
vector<int> paperResult(3, 0);

void DividePaper(int x, int y, int n)
{
	int cur = paper[y][x];
	bool isSamePaper = true;
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (paper[i][j] != cur)
			{
				isSamePaper = false;
				break;
			}
		}
	}

	if (isSamePaper)
	{
		paperResult[cur + 1] ++;
	}
	else
	{
		//구역을 9개의 영역으로 나누며, 구역 한변의 길이는 3의 배수이므로 나누기 3한다.
		int divideRegionThree = n / 3;
		for (int i = y; i < y + n; i += divideRegionThree)
		{
			for (int j = x; j < x + n; j += divideRegionThree)
			{
				DividePaper(j, i, divideRegionThree);
			}
		}
	}
}

int main(void)
{
	FastIO;

	int  N(0); //N*N 크기의 행렬
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> paper[i][j];
		}
	}

	DividePaper(0, 0, N);
	
	for (int i = 0; i < paperResult.size(); i++)
	{
		std::cout << paperResult[i] << "\n";
	}
	return 0;
}