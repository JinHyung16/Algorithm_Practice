#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 A+B-6 - 문자열 알고리즘
/// ,는 항상 string의 index 1번째이므로
/// 0번과 2번 index에서 int값을 꺼내온다.
/// 이때 string[0] - '0'을 해줘야 아스키 코드가 변환된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int T = 0; //테스트 케이스 개수 T
	std::cin >> T;
	while ( T-- )
	{
		int a = 0, b = 0;
		string input;
		std::cin >> input;
		a = input[0] - '0';
		b = input[2] - '0';

		std::cout << a + b << "\n";
	}
	return 0;
}