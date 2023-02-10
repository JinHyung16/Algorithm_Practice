#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 열 개씩 끊어 출력하기 - 문자열 알고리즘
/// 10으로 나눈 나머지가 9여야한다.
/// 왜냐면 index는 0부터 9까지가 총 10개이기 때문이다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int splitCnt = 10;

	string input;
	std::cin >> input;
	
	for (int i = 0; i < input.length(); i++)
	{
		std::cout << input[i];
		if (i % splitCnt == 9)
		{
			std::cout << "\n";
		}
	}
	return 0;
}