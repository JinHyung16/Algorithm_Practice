#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 쇠막대기 - 자료구조 알고리즘
/// 스택을 이용하여 문제를 해결한다. 그 후 들어온 괄호를 보고 스택에 넣는지, 스택에서 빼는지 결정한다.
/// 우선 전체 잘려진 막대의 수는 최종 stack에 들어간 길이와 같으니 이를 저장할 인수 stickCount 변수를 선언.
/// 
/// for i to string.size() 돌면서
/// 1) i번째에 (가 들어온 경우, i-1번째가 )면 i번째는 막대의 끝지점을 의미하므로 스택에 push
/// 2) i번째에 (가 들어온 경우, i-1번째가 (면 아직 막대이거나 레이저일 수 있으니 우선 스택에 push
/// 3) i번째에 )가 들어온 경우, i-1번째가 (면 레이저를 의미하므로 스택에서 pop하고 stickCount += stack.size()
/// 4) i번째에 )가 들어온 경우, i-1번째가 )면 막대 끝을 의미하므로 스택에서 pop하고 stickCount ++
/// 를 다 실행하고 난 뒤 stickCount를 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	string input;
	stack<char> stk;
	int stickCount = 0;

	std::cin >> input;
	for(int i = 0; i < input.size(); i++)
	{
		if(input[i] == '(')
		{
			stk.push(input[i]);
		}
		else
		{
			if(input[i-1] == '(')
			{
				stk.pop();
				stickCount += stk.size();
			}
			else
			{
				stk.pop();
				stickCount++;
			}
		}
	}

	std::cout << stickCount << "\n";

	return 0;
}