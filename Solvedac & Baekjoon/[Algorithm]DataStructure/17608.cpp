#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 막대기 - DataStructure 알고리즘
/// stack에 막대를 입력받아 놓는다.
/// 문제에서 오른쪽에서 본다고 했으니, 이는 배열에 담았을 때
/// 배열엔 맨 왼쪽이 0번째 index이므로 오른쪽에서 본 것을 기준으로 배열 맨 뒤에서부터 꺼내야 한다.
/// 따라서 stack을 이용해 LIFO 개념을 활용한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //막대기 N개
	stack<int> stk;

	int stickCnt = 1;

	std::cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int height = 0;
		std::cin >> height;
		stk.push(height);
	}
	
	int maxHeight = stk.top();
	stk.pop();

	while(!stk.empty())
	{
		if( maxHeight < stk.top())
		{
			maxHeight = stk.top();
			stickCnt += 1;
		}
		stk.pop();
	}

	std::cout << stickCnt << "\n";
	return 0;
}