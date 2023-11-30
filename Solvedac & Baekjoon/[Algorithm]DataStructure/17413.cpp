#include<iostream>
#include<vector>
#include<string>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver3 단어 뒤집기 2 - 자료구조 알고리즘
/// isTag flag와 stack을 이용해 해결했다.
/// 뒤집어야 하는 문자의 경우 stack에 넣었다
/// 이때 뒤집어야 하는 문자가 아닌 경우 그냥 해당 문자를 순수하게 출력하는데
/// 열린 태그 (<)면 항상 stack에 있는게 없는지 확인하면서 stack 내부를 먼저 출력하고
/// 그 다음 문자를 순서대로 출력할 수 있게 해줬다.
/// </summary>

int main(void)
{
	FastIO;
	string input, buf = " ";
	getline(cin, input);
	input += ' '; // 마지막 문자임을 확실하게 구분하기 위해 사용
	stack<char> cStk;
	bool isTag = false;

	for (int i = 0; i < input.size(); i++)
	{
		if(input[i] == '<')
		{
			while (!cStk.empty())
			{
				cout << cStk.top();
				cStk.pop();
			}
			isTag = true;
			cout << input[i];
		}
		else if (input[i] == '>')
		{
			isTag = false;
			cout << input[i];
		}
		else if (isTag)
		{
			cout << input[i];
		}
		else
		{
			if (input[i] == ' ')
			{
				while (!cStk.empty())
				{
					cout << cStk.top();
					cStk.pop();
				}
				cout << " ";
			}
			else
			{
				cStk.push(input[i]);
			}
		}
	}
	return 0;
}