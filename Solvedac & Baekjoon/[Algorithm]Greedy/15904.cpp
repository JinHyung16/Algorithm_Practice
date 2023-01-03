#include<iostream>
#include<string>

/// <summary>
/// Silver5 UCPC는 무엇의 약잘일까? - Greedy 알고리즘
/// UCPC 순서대로 받아올 수 있게 if문 조건 추가가 중요
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string input;
	string result;
	string CheckUCPC = "UCPC";
	std::getline(cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'U' && result.empty())
		{
			result += 'U';
		}
		else if (input[i] == 'C' && result == "U")
		{
			result += 'C';
		}
		else if (input[i] == 'P' && result == "UC")
		{
			result += 'P';
		}
		else if (input[i] == 'C' && result == "UCP")
		{
			result += 'C';
		}
	}

	if (result == CheckUCPC)
	{
		std::cout << "I love UCPC" << std::endl;
	}
	else
	{
		std::cout << "I hate UCPC" << std::endl;
	}
	return 0;
}