#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 에디터 - 자료구조 알고리즘
/// vector의 경우 O(n)걸린다. 따라서 선형 시간에 문제를 해결하려면 O(n)이면 안된다.
/// 
/// 1)stack을 이용해 left right를 나눠 구하는 방식 -> push, pop의 경우 O(1)
/// 명령어를 다 진행했으면 마지막에 right에 있는 값들을 left에 옮기고 left에 있는 값을 다 출력한다.
/// 커서를 왼쪽으로 움직인다는건, left 스택에서 맨 위값을 지운다는 의미. 근데 이때 이 지운값은 오른쪽에서 들고 있어야한다.
/// 커서를 오른쪽으로 움직인다는건, right 스택에서 맨 위값을 지운다는 의미. 근데 이때 이 지운값은 왼쪽에서 들고 있어야한다.
/// 
/// 2)linked list를 이용해 구하는 방식 -> 원소 삽입, 삭제의 경우 O(1)
/// </summary>

using namespace std;

string input;
stack<char> leftStk; //문자를 담을 커서 기준 왼쪽 stack
stack<char> rightStk; //문자를 담을 커서 기준 오른쪽 stack

int main(void)
{
	FastIO;
	
	int M = 0; //명령어 개수
	char cmd =  ' ', ch = ' ';

	std::cin >> input;
	std::cin >> M;

	for(int i = 0; i < input.length(); i++)
	{
		leftStk.push(input[i]); //left stack에 먼저 문자열을 다 넣어둔다.
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