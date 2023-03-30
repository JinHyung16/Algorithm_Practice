#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 최소 힙 - 자료 구조 알고리즘
/// 문제에서 최소힙을 이용하라 했으니, 정렬을 계속 실행할 필요는 없다
/// priority_queue에서 greater는 오름차순을 의미
/// </summary>

using namespace std;

vector<string> noListen;

int main(void)
{
	FastIO;
	
	priority_queue<int, vector<int>, std::greater<int>> pq;

	int N(0); //연산의 개수 N
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		std::cin >> x;
		if (x == 0)
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
			pq.push(x);
		}
	}
	return 0;
}