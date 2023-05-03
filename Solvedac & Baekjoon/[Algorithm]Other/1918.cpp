#include<iostream>
#include<vector>
#include<string>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold2 ���� ǥ��� - �ڷᱸ�� �˰���
/// �־��� ǥ����� ������ stack�� ������� �־�д�.
/// �̶� '('�� ')'������ �� ���̿� �ִ� �����ڸ� stack ������ ���ִ� ������ �����Ѵ�.
/// stack�� ���Լ���� ���߿� ���°� ���� ������ �̸� ���� ��¶� ������� top�������� ������ָ� �ȴ�.
/// 
/// �� �����ڸ� �ִٰ� stack�� top�� '('��� �ǹ̴� ���ĺ��� ���� �����ڸ� ���� ����ؾ� �ϹǷ� ��� stack�� �ִٰ�
/// ')'�� ������ ���� stack�� top�� '('�� �ɶ����� �ݺ��Ͽ� '('���� ���� �����ڸ� �� ���� ����� ����
/// �������� pop�� �ѹ� �� ���༭ '('�� �����Ѵ�. �� �� for���� �� �������� ���� stack�� �ִ°� top���� ����Ѵ�.
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
				result.pop(); //'('�� �����ַ��� �����Ѵ�.
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