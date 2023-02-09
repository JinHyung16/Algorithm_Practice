#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 하얀 칸 - 문자열 알고리즘
/// 보드 1줄을 i, 1줄의 보드 내에서 1칸을 j라고하면
/// 8*8 체스판은
/// i=1 : j=0 1 2 3 4 5 6 7
/// i=2 : j=0 1 2 3 4 5 6 7
/// 이런식으로 채워진다.
/// i=1일땐 흰칸은 1, 3, 5, 7
/// i=2일때 흰칸은 0, 2, 4, 6 이렇게 생성이 되는데
/// 이는 (i%2==0 && j%2==1)과 (i%2==1 && j%2==0)일때 흰색의 조건이 다름을 의미
/// i=0부터하면 조건문이 꼬여서 백준 예시로 정답이 1이 아니라 23이 나온다.
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