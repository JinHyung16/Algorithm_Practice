#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 카드 합체 놀이 - Greedy 알고리즘
/// 합체하고 나서 가장 작은 값이 되려면
/// 애당초 카드를 더해서 합칠 때 가장 작은 수와 그 다음 작은수를 더해가야 한다.
/// 
/// priority_queue를 이용해 항상 오름차순 정렬한다.
/// 그리고 while(m--)을 통해 루프를 돌면서
/// 우선순위 큐에서 top을 두번 꺼낸다. 이때 꺼낼때 마다 pop도 해준다.
/// 그리고 그 두 수를 합쳐서 다시 pq에 두번 넣는다.
/// 왜냐면 문제에서 두 수를 합치고 그 수를 꺼낸 수들에게 덮어쓰니
/// 꺼내는건 항상 2개니깐 두 수의 합치는걸 2번의 push로 대체한다.
/// </summary>


int main(void)
{
	FastIO;

	int n = 0, m = 0; // 카드의 개수 n, 합체 횟수 m
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<long long>> card;

	int input = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		card.push(input);
	}

	while (m--)
	{
		long long smFirst = card.top();
		card.pop();
		long long smSecond = card.top();
		card.pop();
		
		long long sum = smFirst + smSecond;
		card.push(sum);
		card.push(sum);
	}

	long long result = 0;
	while (!card.empty())
	{
		result += card.top();
		card.pop();
	}

	cout << result << "\n";
	return 0;
}