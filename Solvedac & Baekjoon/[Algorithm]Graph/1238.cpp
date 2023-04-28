#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 파티 - Graph 알고리즘
/// Graph의 end지점과 time을 pair 형태로 넣어 저장해둔다.
/// BFS를 실행하면서 우선순위 queue에 거리가 큰 순서대로 오름차순해서 들어올 수 있게하고,
/// timeVec은 각 지점마다 걸리는 시간으로 최댓값으로 설정해둔다.
/// priority_queue에는 {걸리는 시간, 현재 위치} 형식으로 저장해둔다.
/// 
/// while문을 실행하면서, graph[curPos]의 크기만큼 도는데 이 의미는 1번 노드와 연결된 모든 노드를 돌겠다는 의미다.
/// 이렇게 돌면서 현재 시간이 배열에 저장된 시간보다 크면 패스, 작으면 다음 경로까지 걸리는 시간과 현재 시간을 합쳐서 저장해두고
/// pq에 넣어둔다. 이렇게 반복하여 최종적으로 가장 긴 시간을 출력한다.
/// </summary>

using namespace std;

int N(0), M(0); //N명의 학생, M개의 단방향 도로
vector<pair<int, int>> graph[1001];
vector<int> timeVec(1001, 98765);
vector<int> resultTime(1001, 0);

void BFS_Dijkstra(int start)
{
	timeVec.clear();
	timeVec.resize(N + 1, 98765);
	timeVec[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int curTime = pq.top().first;
		int curPos = pq.top().second;
		pq.pop();

		if (timeVec[curPos] < curTime)
		{
			continue;
		}

		for (int i = 0; i < graph[curPos].size(); i++)
		{
			int nextPos = graph[curPos][i].first;
			int next_time = curTime + graph[curPos][i].second;

			if (next_time < timeVec[nextPos])
			{
				timeVec[nextPos] = next_time;
				pq.push(make_pair(next_time, nextPos));
			}
		}
	}
}

int main(void)
{
	FastIO;

	int X(0); //모든 학생은 집에서 X로 X에서 집으로 오고 갈 수 있다.
	std::cin >> N >> M >> X;

	for (int i = 0; i < M; i++)
	{
		int start(0), end(0), time(0);
		std::cin >> start >> end >> time;
		graph[start].push_back({ end,time });
	}

	for (int i = 1; i <= N; i++)
	{
		BFS_Dijkstra(i);
		resultTime[i] = timeVec[X];
	}
	BFS_Dijkstra(X);
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		resultTime[i] += timeVec[i];
		result = std::max(result, resultTime[i]);
	}
	std::cout << result << "\n";
	return 0;
}