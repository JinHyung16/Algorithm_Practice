#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ������ - �ڷᱸ�� �˰���
/// vector�� ��� O(n)�ɸ���. ���� ���� �ð��� ������ �ذ��Ϸ��� O(n)�̸� �ȵȴ�.
/// 
/// 1)stack�� �̿��� left right�� ���� ���ϴ� ��� -> push, pop�� ��� O(1)
/// ��ɾ �� ���������� �������� right�� �ִ� ������ left�� �ű�� left�� �ִ� ���� �� ����Ѵ�.
/// Ŀ���� �������� �����δٴ°�, left ���ÿ��� �� ������ ����ٴ� �ǹ�. �ٵ� �̶� �� ����� �����ʿ��� ��� �־���Ѵ�.
/// Ŀ���� ���������� �����δٴ°�, right ���ÿ��� �� ������ ����ٴ� �ǹ�. �ٵ� �̶� �� ����� ���ʿ��� ��� �־���Ѵ�.
/// 
/// 2)linked list�� �̿��� ���ϴ� ��� -> ���� ����, ������ ��� O(1)
/// </summary>

using namespace std;

string input;
stack<char> leftStk; //���ڸ� ���� Ŀ�� ���� ���� stack
stack<char> rightStk; //���ڸ� ���� Ŀ�� ���� ������ stack

int main(void)
{
	FastIO;
	
	int M = 0; //��ɾ� ����
	char cmd =  ' ', ch = ' ';

	std::cin >> input;
	std::cin >> M;

	for(int i = 0; i < input.length(); i++)
	{
		leftStk.push(input[i]); //left stack�� ���� ���ڿ��� �� �־�д�.
	}

	for(int i = 0; i < M; i++)
	{
		std::cin >> cmd;

		if(cmd == 'L')
		{
			if(leftStk.empty()) { continue; }
			else
			{
				rightStk.push(leftStk.top());
				leftStk.pop();
			}
		}
		else if(cmd == 'D')
		{
			if(rightStk.empty()) { continue; }
			else
			{
				leftStk.push(rightStk.top());
				rightStk.pop();
			}
		}
		else if(cmd == 'B')
		{
			if(leftStk.empty()) { continue; }
			else
			{
				leftStk.pop();
			}
		}
		else if(cmd == 'P')
		{
			std::cin >> ch;
			leftStk.push(ch);
		}
	}
	
	while(!leftStk.empty())
	{
		rightStk.push(leftStk.top());
		leftStk.pop();
	}

	while(!rightStk.empty())
	{
		std::cout << rightStk.top();
		rightStk.pop();
	}

	return 0;
}