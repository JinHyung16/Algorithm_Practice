#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 8진수 2진수 - 문자열 알고리즘
/// 8진수의 한 자리를 2진수로 변환한다.
/// ex) 314 => 3(011) 1(001) 4(100)
/// 이때 맨 앞이 0이면 안되므로 11001100으로 쓴다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string octalToBinary[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
	string octalNum;
	std::cin >> octalNum;

	for ( int i = 0; i < octalNum.length(); i++ )
	{
		int temp = octalNum[i] - '0';
		if ( i == 0 )
		{
			std::cout << std::stoi(octalToBinary[temp]);
		}
		else
		{
			std::cout << octalToBinary[temp];
		}
	}

	return 0;
}