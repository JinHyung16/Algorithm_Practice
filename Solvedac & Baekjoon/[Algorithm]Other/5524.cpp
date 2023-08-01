#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 입실 관리 - 문자열 알고리즘
/// std::tolwer(string)은 대문자를 소문자로 바꿔주는 함수다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //N명의 입실자

	std::cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		string input;
		std::cin >> input;
		for ( int i = 0; i < input.length(); i++ )
		{
			if ( 'A' <= input[i] <= 'Z' )
			{
				input[i] = std::tolower(input[i]);
			}
			else
			{
				continue;
			}
		}
		std::cout << input << "\n";
	}

	return 0;
}