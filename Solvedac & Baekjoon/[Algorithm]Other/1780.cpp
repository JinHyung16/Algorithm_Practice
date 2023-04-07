#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ������ ���� - ���� ���� �˰���
/// N�� 3�� ������ ũ�� ���̴�. ���� ���ҽ� /3���� ������ �������Ѵ�.
/// N�� �ִ�� 3^7���� 2183�̴�.
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
		//������ 9���� �������� ������, ���� �Ѻ��� ���̴� 3�� ����̹Ƿ� ������ 3�Ѵ�.
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

	int  N(0); //N*N ũ���� ���
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