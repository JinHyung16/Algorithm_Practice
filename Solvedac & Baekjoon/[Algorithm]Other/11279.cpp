#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 최대 힙 - 자료 구조 알고리즘
/// priority_queue<int> pq 의 의미는 priority_queue<int, vector<int>, std::less<int>> pq 랑 같은 의미다.
/// 기본이 내림차순임을 생각해서 우선 순위 큐를 만들고 문제 조건에 맞춰 해결한다.
/// </summary>

using namespace std;

vector<bool> visited(1000001, false);

int main(void)
{
	FastIO;

	int N(0); //연산의 개수 N
	std::cin >> N;

	priority_queue<int> pq;

	while (N--)
	{
		int input(0);
		std::cin >> input;
		if (input == 0)
		{
			if (pq.empty())
			{
				std::cout << 0 << "\n";
			}
			else
			{
				std::cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(input);
		}
		
	}
	
	return 0;
}