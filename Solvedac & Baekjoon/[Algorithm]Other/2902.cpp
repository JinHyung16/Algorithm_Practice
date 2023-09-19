#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 KMP는 왜 KMP일까? - 문자열 알고리즘
/// 결국 문제를 보면 대문자만 출력하니, string[i]가 대문자면 그것만 따로 모아 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	string input;
	std::cin >> input;
	string result;
	for ( int i = 0; i < input.length(); i++ )
	{
		if ( 'A' <= input[i] && input[i] <= 'Z')
		{
			result += input[i];
		}
	}

	std::cout << result << "\n";
	return 0;
}