#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 오큰수 - 자료구조 알고리즘
/// 오큰수는 Ai보다 오른쪽에 있으면서, Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다.
/// 
/// 1) vector에 수들을 받는다.
/// 2) vector의 맨 뒤부터 거꾸로 오큰수를 탐색해가면서 seqStk에 vector[i]값을 넣는다.
/// 3) seqStk가 비어있지 않으면 seqStk이 빌때까지 돌면서 seqStk의 top <= sequence[i]면 seqStk.pop, 아니면 break한다.
/// 4) seqStk이 empty면 resultStk.push(-1)을 아니라면 resultStk.push(seqStk.top())을 한다.
/// 
/// 반례) N=5, 1 8 5 7 9 일때
/// 정답 -> 8 9 7 9 -1 / 오답 -> 8 -1 7 9 -1 (주의하자)
/// 
/// 8을 볼때쯤 seqStk에는 5, 7, 9가 쌓여있으니 seqStk.pop()이 2번 실행되어 seqStk.top()은 9가 남고 break; 실행된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //수열 A의 크기
	std::cin >> N;

	vector<int> sequence(N, 0);
	stack<int> seqStk;
	stack<int> resultStk;
	
	for(int i = 0; i < N; i++)
	{
		std::cin >> sequence[i];
	}
	
	for(int i = N-1; 0 <= i; i--)
	{
		while(!seqStk.empty())
		{
			if(seqStk.top() <= sequence[i])
			{
				seqStk.pop();
			}
			else
			{
				break;
			}
		}

		if(seqStk.empty())
		{
			resultStk.push(-1);
		}
		else
		{
			resultStk.push(seqStk.top());
		}

		seqStk.push(sequence[i]);
	}

	while(!resultStk.empty())
	{
		std::cout << resultStk.top() << " ";
		resultStk.pop();
	}
	return 0;
}