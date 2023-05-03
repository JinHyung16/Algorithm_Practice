#include<iostream>
#include<vector>
#include<string>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold2 후위 표기식 - 자료구조 알고리즘
/// 주어진 표기식이 나오면 stack에 순서대로 넣어둔다.
/// 이때 '('와 ')'나오면 이 사이에 있는 연산자를 stack 앞으로 빼주는 과정을 진행한다.
/// stack은 후입선출로 나중에 들어온게 먼저 나오니 이를 최종 출력때 순서대로 top에서부터 출력해주면 된다.
/// 
/// 즉 연산자를 넣다가 stack의 top이 '('라는 의미는 이후부터 들어온 연산자를 먼저 출력해야 하므로 계속 stack에 넣다가
/// ')'가 나오는 순간 stack의 top이 '('가 될때까지 반복하여 '('이후 들어온 연산자를 다 빼서 출력한 다음
/// 마지막에 pop을 한번 더 해줘서 '('를 제거한다. 그 후 for문이 다 끝났으면 남은 stack에 있는걸 top부터 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	string input;
	std::cin >> input;

	stack<char> result;

	for (int i = 0; i < input.size(); i++)
	{
		if ('A' <= input[i] && input[i] <= 'Z')
		{
			std::cout << input[i];
		}
		else
		{
			if (input[i] == '(')
			{
				result.push(input[i]);
			}
			else if (input[i] == '*' || input[i] == '/')
			{
				while (!result.empty() && (result.top() == '*' || result.top() == '/'))
				{
					std::cout << result.top();
					result.pop();
				}
				result.push(input[i]);
			}
			else if (input[i] == '-' || input[i] == '+')
			{
				while (!result.empty() && result.top() != '(')
				{
					std::cout << result.top();
					result.pop();
				}
				result.push(input[i]);
			}
			else if (input[i] == ')')
			{
				while (!result.empty() && result.top() != '(')
				{
					std::cout << result.top();
					result.pop();
				}
				result.pop(); //'('를 지워주려고 실행한다.
			}
		}
	}

	while (!result.empty())
	{
		std::cout << result.top();
		result.pop();
	}

	return 0;
}