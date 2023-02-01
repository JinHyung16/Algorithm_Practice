#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 특정 거리의 도시 찾기 - Graph 알고리즘
/// 단반향 그래프임을 생각해 도시를 이어준다.
/// 그 후 BFS를 통해 돌면서 visited를 초기 -1로 해놓고,
/// 초기 시작 지점은 visited은 0으로 초기화하고 그 다음 도시가
/// 방문 가능하다면 이전 도시의 visited 값에서 +1한다
/// 이후 다 방문했다면, 거리가 K인 도시들을 result에 담는 과정을 수행한다.
/// </summary>

using namespace std;

int N(0), M(0), K(0), X(0); //도시 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
vector<vector<int>> graph;
vector<int> visited;
vector<int> result; //거리가 K인 도시 넣기

void BFS()
{
	queue<int> q;
	q.push(X);

	visited[X] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		//현재 도시를 기준으로 연결된 도시 탐색하기
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i]; //다음 도시 번호로 이동
			if (visited[next] == -1)
			{
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == K)
		{
			//거리가 K인 도시 번호 오름차순으로 넣기
			result.push_back(i);
		}
	}
}
int main(void)
{
	FastIO;
	
	std::cin >> N >> M >> K >> X;

	graph.resize(N + 1);
	visited.resize(N + 1, -1);
	//graph = vector<vector<int>>(N + 1);

	for (int i = 0; i < M; i++)
	{
		int start, end;
		std::cin >> start >> end;
		//단반항 그래프라고 했으니, start에서 end로 이어준다
		graph[start].push_back(end);
	}

	BFS();

	if (result.size() == 0)
	{
		std::cout << -1 << "\n";
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			std::cout << result[i] << "\n";
		}
	}
	return 0;
}