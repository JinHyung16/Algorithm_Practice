#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 효율적인 해킹 - 그래프이론 알고리즘
/// BFS를 통해 문제를 해결한다.
/// 먼저 A가 B를 신뢰한다 했으니, vector[B].push_back(A);를 한다. 그래야 B가 왔을 때 A까지 BFS 탐색이 가능하다.
/// 그 후 탐색을 진행하면서 탐색이 가능할 때마다 해킹한 횟수를 카운드하여 이를 N까지 for문을 돌린다.
/// 이때 카운트 횟수와, 시작 지점에 대해 vector<pair<int,int>>로 저장해둔다.
/// 그 후 탐색이 다 끝나면 가장 큰 탐색 횟수를 찾고,
/// for문을 통해 카운트 횟수와, 시작 지점에 대해 저장한 배열을 다 탐색하면서 가장 큰 탐색 횟수와 같은 경우만 출력한다.
/// </summary>

using namespace std;

int N = 0, M = 0;
vector<int> computer[10001];
vector<bool> visited(10001, false);
vector<pair<int, int>> hackPC;
int canHackCnt = 1;

void BFS(int start)
{
	visited[start] = true;
	queue<int> q;
	q.push(start);

	while ( !q.empty() )
	{
		int cur = q.front();
		q.pop();

		for ( int i = 0; i < computer[cur].size(); i++ )
		{
			int next = computer[cur][i];

			if ( !visited[next] )
			{
				visited[next] = true;
				q.push(next);
				canHackCnt++;
			}
		}
	}
}

void Reset()
{
	for ( int i = 0; i <= N; i++ )
	{
		visited[i] = false;
	}
}

int main(void)
{
	FastIO;
	
	std::cin >> N >> M;
	for ( int i = 0; i < M; i++ )
	{
		int A = 0, B = 0;
		std::cin >> A >> B;
		computer[B].push_back(A);
	}

	for ( int i = 1; i <= N; i++ )
	{
		BFS(i);
		Reset();
		hackPC.push_back(make_pair(i, canHackCnt));
		canHackCnt = 1;
	}

	int maxHackCnt = -1;
	for ( int i = 0; i < hackPC.size(); i++ )
	{
		if ( maxHackCnt < hackPC[i].second )
		{
			maxHackCnt = hackPC[i].second;
		}
	}

	for ( int i = 0; i < hackPC.size(); i++ )
	{
		if ( hackPC[i].second == maxHackCnt )
		{
			std::cout << hackPC[i].first << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}