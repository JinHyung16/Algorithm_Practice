#include<iostream>
#include<vector>
#include<string>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 �������� ���� - �ڷᱸ�� �˰���
/// ���� ���� �Է��� �޾ƾ��ϸ�, (.)�� ���� ������ �ɶ����� ���ڿ� ���پ� �ޱ�
/// ¦���� �̷�� ��ȣ�� �˷��� stack�� �̿��� �ڽ� �ٷ� ���� ¦�� �̷�°��� ���Ѵ�.
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