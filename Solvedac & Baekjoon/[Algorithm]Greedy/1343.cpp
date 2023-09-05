#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 �������̳� - �׸��� �˰���
/// ���� Ž���Ͽ� �� ã�ų�
/// �ƴϸ� �Է� ���� ���ڸ� "AAAA",�� "BB"�� �ٲٴ� ����� �ִµ�
/// ���� �ٲٴ� ������� �ذ��ߴ�.
/// �Է� ���� ���ڿ����� X��ŭ cnt�� ������Ű��, "."�� ������ cnt��ŭ B�� A�� �߰��Ѵ�.
/// for���� �� ���� ���� ���� cnt % 2 == 1�̸� -1�� �ƴϸ� result �� B�� A�� �߰��� ���� ����Ѵ�.
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