#include<iostream>
#include<vector>
#include<string>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 균형잡힌 세상 - 자료구조 알고리즘
/// 공백 없이 입력을 받아야하며, (.)이 들어올 때까지 될때까지 문자열 한줄씩 받기
/// 짝꿍을 이루는 괄호를 알려면 stack을 이용해 자신 바로 위가 짝을 이루는건지 비교한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string input;
	while (true)
	{
		stack<char> stk;
		std::getline(cin, input);
		if (input[0] == '.') 
		{
			break;
		}
		for (int i = 0; i < input.length() - 1; i++)
		{
			if (input[i] == '(')
			{
				stk.push('(');
			}
			if (input[i] == '[')
			{
				stk.push('[');
			}

			if (input[i] == ')')
			{
				if (!stk.empty() && stk.top() == '(') 
				{
					stk.pop();
				}
				else
				{
					std::cout << "no" << "\n";
					break;
				}
			}
			if (input[i] == ']')
			{
				if (!stk.empty() && stk.top() == '[')
				{
					stk.pop();
				}
				else
				{
					std::cout << "no" << "\n";
					break;
				}
			}

			if (stk.empty() && i == input.length() - 2)
			{
				std::cout << "yes" << "\n";
			}
			else if(!stk.empty() && i == input.length() - 2)
			{
				std::cout << "no" << "\n";
			}
		}
	}
	return 0;
}