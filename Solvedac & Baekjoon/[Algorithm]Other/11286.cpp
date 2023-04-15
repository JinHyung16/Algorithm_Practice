#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 절댓값 힙 - 자료구조 알고리즘
/// priority queue를 이용해 문제를 해결한다.
/// 1. 0이 들어오면 배열에서 절댓값이 가장 작은 값을 출력하고 이 값을 배열에서 제거
/// 2. 0이 아니라면 배열에 x값을 넣는다.
/// priority queue를 이용해 절댓값이 같으면 작은 숫자가 맨 앞에 오게 정렬하면서 넣는다.
/// priority queue에서 구조체를 사용하면 구조체 내부에서 연산자 오버 로딩을 통해 우선순위를 원하게 바꿀 수 있다. 
/// </summary>

using namespace std;

struct absGrater 
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
		{
			//절댓값이 같다면 음수가 제일 앞에 오면서 오름차순
			auto c = a > b;
			return a > b;
		}
		else
		{
			//아니라면 그냥 절댓값 크기 순서대로 오름차순
			auto c = abs(a) > abs(b);
			return abs(a) > abs(b);
		}
	}
};

int main(void)
{
	FastIO;
	
	int N(0); //연산의 개수 N
	int x(0);
	priority_queue<int, vector<int>, absGrater> pq;
	std::cin >> N;
	while (N--)
	{
		std::cin >> x;
		if (x == 0)
		{
			if (!pq.empty())
			{
				std::cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{
				std::cout << 0 << "\n";
			}
		}
		else
		{
			pq.push(x);
		}
	}
	return 0;
}