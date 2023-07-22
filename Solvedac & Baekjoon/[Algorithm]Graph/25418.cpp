#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 정수 a를 k로 만들기 - Graph 알고리즘
/// 이 문제를 그래프로 보려면 시선을 바꿔야 한다.
/// 모든 수 N에 대해 N+1과 N*2로 가는 거리가 1인 간선이 있고,
/// A에서 K까지의 최소 거리를 구하는 문제라고 생각한다.
/// </summary>

using namespace std;


int A = 0, K = 0; //양의 정수 A를 K로 바꾼다.
int MAX_NUM = 1000000; //K의 최대값이 1000000이니 이 값을 MAX값으로 설정한다.
vector<int> graph(1000000, 0); //초기 최소 거리는 다 0이다.

int BFS(int start)
{
	queue<int> q;
	q.push(start);

	while ( !q.empty() )
	{
		int cur = q.front();
		q.pop();

		if ( cur == K )
		{
			return graph[cur];
		} 
		if ( cur + 1 <= MAX_NUM && graph[cur + 1] == 0)
		{
			q.push(cur + 1);
			graph[cur + 1] = graph[cur] + 1;
		}
		if ( cur * 2 <= MAX_NUM && graph[cur * 2] == 0 )
		{
			q.push(cur * 2);
			graph[cur * 2] = graph[cur] + 1;
		}
	}
}

int main(void)
{
	FastIO;

	std::cin >> A >> K;

	int minResult = BFS(A);

	std::cout << minResult << "\n";
	return 0;
}