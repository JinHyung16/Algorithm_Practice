#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ������ ����� - ���� ���� �˰���
/// ���� ���� ������ 1��и�, 2��и�, 3��и�, 4��и����� ���� ��ӵ���.
/// �̶� �� ��и��� ���� ��ǥ�� ����/2 �� ���ؼ� ������.
/// �� ��и��� ���� üũ�ϴ� ������ ��� ȣ���� �ȵ����� üũ�ؾ��Ѵ�.
/// </summary>

using namespace std;

int whiteRegion(0), blueRegion(0);
vector<vector<int>> paper(129, vector<int>(129, 0)); //N�� �ִ밡 2^7�̹Ƿ�

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

	//��� ȣ��� for���ȿ��� ������Ű�� ���� �� �þ�⿡ ��� ȣ���� �ȵȰ�츸 üũ�ؾ��Ѵ�.
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

	int  N(0); //������ ������ N
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