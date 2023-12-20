#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver5 자료구조는 정말 최고야 - 자료구조 알고리즘
/// 우선 순위큐를 greater 즉 오름차순으로(작은 순서대로) 넣는다.
/// 이때 책과 해당 책이 어느더미 몇 번째 있는지 넣는다.
/// while문을 돌면서 맨 위에서 책을 꺼내 각 더미의 맨 위에 있는지 확인한다.
/// 없다면 No 있다면 Yes를 출력한다.
/// </summary>

int main(void)
{
	FastIO;
	
	int N = 0, M = 0; // N권 교과서, 더미 M개
	cin >> N >> M;
	int K = 0; // 더미 개수 K
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	vector<int> lis(M, 0);

	for (int i = 0; i < M; i++)
	{
		int temp = 0;
		cin >> K;
		for (int j = K-1; 0 <= j; j--)
		{
			cin >> temp;
			pq.push(make_pair(temp, make_pair(i, j)));
		}
	}
	
	while (!pq.empty())
	{
		pair<int, pair<int, int>> tmpPair = pq.top();
		pq.pop();
		if (lis[tmpPair.second.first]++ != tmpPair.second.second) 
		{
			cout << "No" << "\n";
			return 0;
		}
	}
	cout << "Yes" << "\n";
	return 0;
}