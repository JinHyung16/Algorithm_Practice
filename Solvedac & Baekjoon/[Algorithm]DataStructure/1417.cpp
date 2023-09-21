#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 국회의원 선거 - 자료구조 알고리즘
/// 기호 1번이 다솜이니 1번을 제외하고 나머지 사람 중 큰 득표수를 갖고 있는 사람의 득표를 가져온다.
/// pq에 다솜이 보다 큰 득표수들을 넣고, 여기서 하나씩 값을 빼고 줄여가면서 다솜이보다 작을 때 까지 돌린다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0;
	int temp = 0; //다솜이 득표수
	int result = 0;
	priority_queue<int> pq;
	std::cin >> N;

	for ( int i = 0; i < N; i++ )
	{
		int input = 0;
		std::cin >> input;
		if ( i == 0 )
			temp = input;
		if ( temp <= input && i != 0 )
			pq.push(input);
	}
	while ( !pq.empty() && temp <= pq.top() )
	{
		int top = pq.top();
		pq.pop();
		top--;
		result++;
		temp++;
		pq.push(top);
	}

	std::cout << result << "\n";
	return 0;
}