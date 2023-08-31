#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 개표 - 문자열 알고리즘
/// 입력받고 A면 a의 수를 B면 b의 수를 중가시킨다.
/// 그 후 if문을 통해 조건에 맞게 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int V = 0; //심사위원의 수 V
	int a = 0, b = 0; //a참가자 수 b참가자 수
	string input;
	std::cin >> V;
	std::cin >> input;

	for ( int i = 0; i < input.size(); i++ )
	{
		if ( input[i] == 'A' )
		{
			a++;
		}
		else
		{
			b++;
		}
	}

	if ( a < b )
	{
		std::cout << "B" << "\n";
	}
	else if ( b < a )
	{
		std::cout << "A" << "\n";
	}
	else
	{
		std::cout << "Tie" << "\n";
	}

	return 0;
}