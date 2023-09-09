#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 너구리 구구 - 그래프이론 알고리즘
/// 양방향 그래프에 대해 거리 C도 저장할 수 있게 pair를 이용한다.
/// 최대 거리를 갱신하는데, 만약 도착 지점과 거리가 이미 같다면 빠르게 패스하여 시간을 단축한다.
/// </summary>

using namespace std;

int N = 0;
vector<pair<int, long long>> graph[5010]; //a와 b를 연결


long long DFS(int start, long long distance)
{
	long long result = 0;
	for ( int i = 0; i < graph[start].size(); i++ )
	{
		if ( graph[start][i].first == distance )
		{
			continue;
		}
		result = std::max(result, DFS(graph[start][i].first, start) + graph[start][i].second);
	}
	return result;
}

int main(void)
{
	FastIO;

	std::cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		int A = 0, B = 0, C = 0;
		std::cin >> A >> B >> C;
		graph[A].push_back(make_pair(B, C));
		graph[B].push_back(make_pair(A, C));
	}

	std::cout << DFS(1, -1) << "\n";
	return 0;
}