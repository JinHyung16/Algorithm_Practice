#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 대소문자 바꾸기 - 구현 알고리즘
/// 아스키 코드에서 소문자 'a'와 대문자 'A'는 32가 차이난다.
/// 아스키 코드에서 A-Z = 65-90
/// 아스키 코드에서 a-z = 97-122
/// </summary>


int main(void)
{
	FastIO;

	string input;
	cin >> input;

	for ( int i = 0; i < input.size(); i++ )
	{
		if ( 'A' <= input[i] && input[i] <= 'Z' )
		{
			input[i] += 32;
		}
		else if ( 'a' <= input[i] && input[i] <= 'z' )
		{
			input[i] -= 32;
		}
	}

	cout << input << "\n";

	return 0;
}