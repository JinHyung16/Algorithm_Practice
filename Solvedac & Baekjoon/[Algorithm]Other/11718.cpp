#include<iostream>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze5 그대로 출력하기 - 문자열 알고리즘
/// std::cin을 통해 입력받은 변수를 그대로 std::cout한다
/// 이때 문제에선 공백 입력시 공백은 출력하지 않고 종료이므로,
/// getline을 통해 입력받아 공백이면 break로 나간다.
/// 이때 input == " "과 input == ""는 차이가 있으므로 알아두자.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	string input;
	while ( true )
	{
		getline(std::cin, input);
		if ( input == "" )
		{
			break;
		}
		std::cout << input << "\n";
	}
	return 0;
}