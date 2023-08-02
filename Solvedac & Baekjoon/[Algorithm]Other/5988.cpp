#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 홀수일까 짝수일까 - 문자열 알고리즘
/// 문자열을 입력받고, length()-1을 한다.
/// 이유는 string 마지막은 공백이 들어가 있으니.
/// 그 후 % 2를 진행하여 0이면 even(짝수), 1이면 odd(홀수)를 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //숫자의 개수 N
	std::cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		string input;
		std::cin >> input;
		if ( input[input.length() - 1] % 2 == 0 )
		{
			std::cout << "even" << "\n";
		}
		else
		{
			std::cout << "odd" << "\n";
		}
	}
	return 0;
}