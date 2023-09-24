#include<iostream>
#include<vector>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 좋은 단어 - 자료구조 알고리즘
/// AABB 또는 ABBA 또는 BAAB 이런 식으로 나와야 좋은 단어다.
/// 따라서 stack의 단어를 하나씩 넣는다.
/// stack의 top()부분과 단어의 j번째가 같다면 stack에서 지우며
/// stack이 비었을 때마다 카운팅을 해준다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //단어의 수 N
	int goodCnt = 0; //좋은 단어 개수
	std::cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		string input;
		std::cin >> input;
		stack<char> stk;
		for ( int j = 0; j < input.size(); j++ )
		{
			if ( !stk.empty() && stk.top() == input[j] )
			{
				stk.pop();
				continue;
			}
			stk.push(input[j]);
		}
		if ( stk.empty() )
		{
			goodCnt++;
		}

	}

	std::cout << goodCnt << "\n";
	return 0;
}