#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 폴리오미노 - 그리디 알고리즘
/// 선형 탐색하여 다 찾거나
/// 아니면 입력 받은 문자를 "AAAA",나 "BB"로 바꾸는 방법이 있는데
/// 나는 바꾸는 방식으로 해결했다.
/// 입력 받은 문자열에서 X만큼 cnt를 증가시키고, "."가 나오면 cnt만큼 B나 A를 추가한다.
/// for문을 다 돌고 나서 남은 cnt % 2 == 1이면 -1을 아니면 result 즉 B나 A를 추가한 값을 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	string a = "AAAA", b = "BB";
	string board, result;
	int cnt = 0;

	std::cin >> board;
	board += ' ';

	for ( int i = 0; i < board.size(); i++ )
	{
		if ( board[i] == 'X' )
		{
			cnt++;
		}

		if ( board[i] == '.' )
		{
			result += ".";
			if ( cnt % 2 != 0 )
			{
				break;
			}
			else
			{
				cnt = 0;
			}
		}

		if ( cnt == 2 && board[i + 1] != 'X' )
		{
			result += b;
			cnt = 0;
		}
		else if ( cnt == 4 )
		{
			result += a;
			cnt = 0;
		}
	}

	if ( cnt % 2 == 1 )
	{
		std::cout << -1 << "\n";
	}
	else
	{
		std::cout << result << "\n";
	}
	return 0;
}