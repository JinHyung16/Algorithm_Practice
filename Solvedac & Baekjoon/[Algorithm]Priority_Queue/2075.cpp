#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 N번째 큰 수 - 우선순위 큐 알고리즘
/// 초기엔 우선순위 큐를 내림차순으로 정렬할 수 있게 하여 다 넣은 후
/// 마지막에 (N-1)개를 pop해서 pq.top()을 출력했더니 메모리 문제가 생겼다.
/// 
/// 이에 pq를 오름차순 정렬로 바꾼 후 입력을 받을 때 N < pq.size()인 경우 pq.pop()을 했다.
/// 왜냐면 오름차순으로 N개 이상이면 pop시 가장 작은게 사라지기 때문이다.
/// 결국 N*N을 다 입력받았을 땐 pq안에는 가장 큰 수 기준 5개가 오름차순 정렬로 들어와있게된다.
/// </summary>


int main(void)
{
	FastIO;

	int N = 0; // N*N 크기의 표
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	int input = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			pq.push(input);

			if (N < pq.size())
				pq.pop();
		}

	}
	cout << pq.top() << "\n";
	return 0;
}