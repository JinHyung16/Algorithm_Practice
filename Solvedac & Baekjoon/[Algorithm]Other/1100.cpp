#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 �Ͼ� ĭ - ���ڿ� �˰���
/// ���� 1���� i, 1���� ���� ������ 1ĭ�� j����ϸ�
/// 8*8 ü������
/// i=1 : j=0 1 2 3 4 5 6 7
/// i=2 : j=0 1 2 3 4 5 6 7
/// �̷������� ä������.
/// i=1�϶� ��ĭ�� 1, 3, 5, 7
/// i=2�϶� ��ĭ�� 0, 2, 4, 6 �̷��� ������ �Ǵµ�
/// �̴� (i%2==0 && j%2==1)�� (i%2==1 && j%2==0)�϶� ����� ������ �ٸ��� �ǹ�
/// i=0�����ϸ� ���ǹ��� ������ ���� ���÷� ������ 1�� �ƴ϶� 23�� ���´�.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	int whiteCnt(0);
	string board;
	
	for (int i = 1; i <= 8; i++)
	{
		std::cin >> board;
		for (int j = 0; j < board.length(); j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 != 0)
				{
					if (board[j] == 'F')
					{
						whiteCnt++;
					}
				}
			}
			else
			{
				if (j % 2 == 0)
				{
					if (board[j] == 'F')
					{
						whiteCnt++;
					}
				}
			}
		}
	}

	std::cout << whiteCnt << "\n";
	return 0;
}