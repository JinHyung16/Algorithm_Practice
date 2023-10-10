#include<iostream>
#include<vector>
#include<queue>


#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold5 숨박꼭질 3 - Graph 알고리즘
/// BFS는 모든 간선의 가중치가 동일하다는 전제가 있는데,
/// 문제에선 순간이동은 0초, 이동은 1초로 순간이동의 우선 순위가 더 높다.
/// 우선 순위 큐에 시간과 현재 위치를 넣는다.
/// 이 때, 초기 값은 {time, start} = {0, N}으로 넣는다.
/// 그 후 3개의 if문을 통해 움직이는데 x * 2 -> x + 1 -> x - 1 순서대로 if문을 넣고 각 움직이는
/// 방법에 따라 시간은 time 또는 time + 1을 넣는다.
/// </summary>

const int maxMovePos = 100001;

int visited[100001] = { false, };
int minMoveTime = 0;

void BFS(int start, int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	visited[start] = true;

	while ( !pq.empty() )
	{
		int time = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if ( cur == end )
		{
			minMoveTime = time;
		}

		if ( cur * 2 < maxMovePos && !visited[cur * 2] )
		{
			pq.push(make_pair(time, cur * 2));
			visited[cur * 2] = true;
		}

		if ( cur + 1 < maxMovePos && !visited[cur + 1] )
		{
			pq.push(make_pair(time + 1, cur + 1));
			visited[cur + 1] = true;
		}

		if ( 0 <= cur - 1 && !visited[cur - 1] )
		{
			pq.push(make_pair(time + 1, cur - 1));
			visited[cur - 1] = true;
		}
	}

}

int main(void)
{
	FastIO;

	int N = 0, K = 0; //수빈이 위치 N, 동생 위치 K
	cin >> N >> K;

	BFS(N, K);
	cout << minMoveTime << "\n";
	return 0;
}