#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 !밀비 급일 - 문자열 알고리즘
/// getline(cin, string)를 통해 문자열을 공백 포함해서 받는다.
/// 문자열의 맨 끝은 공백이 들어가서 for문의 경우 length - 1 해야지
/// 우리가 원하는 문자열 맨 끝부터 맨 처음까지 문자만 1개씩 출력할 수 있다.
/// 아니면 reverse를 사용해서 뒤집고 출력한다.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	while (true)
	{
		string input;
		std::getline(cin, input);

		if (input == "END")
		{
			break;
		}

		std::reverse(input.begin(), input.end());
		std::cout << input << "\n";

		/*
		for (int i = input.length() - 1; 0 <= i; i--)
		{
			std::cout << input[i];
		}
		std::cout << "\n";
		*/
	}

	return 0;
}