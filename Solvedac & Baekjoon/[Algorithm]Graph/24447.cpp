#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 알고리즘 수업-너비 우선 탐색4 - Graph 알고리즘
/// 정점 방문은 오름차순을 기준으로 방문한다.
/// 무방향 그래프로, u와 v의 각 노드를 연결하고
/// 이를 sort하여 오름차순으로 정럴한다.
/// 
/// depthVec에 깊이를 저장함과 동시에 -1은 아직 방문하지 않은 노드임을 의미하닌 이걸로 체크한다.
/// visitNum은 방문 순서를 저장해둔다.
/// 최종적으로 방문순서 * 깊이를 다 더한값을 출력해야 한다.
/// </summary>

using namespace std;

vector<int> graph[100001];
long long depthVec[100001];
long long visitNum[100001];

void BFS(int start)
{
	int numCnt = 1;
	queue<int> q;
	q.push(start);
	depthVec[start] = 0;
	visitNum[start] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (depthVec[next] == -1)
			{
				//아직 방문하지 않은 노드라면 깊이가 -1이다.
				depthVec[next] = depthVec[cur] + 1;
				numCnt += 1;
				visitNum[next] = numCnt;
				q.push(next);
			}
		}
	}

}

int main(void)
{
	FastIO;
	
	int N(0), M(0), R(0); //정점의 수 N, 간선의 수 M, 시작 정점 R
	std::cin >> N >> M >> R;

	for (int i = 1; i <= M; i++)
	{
		int u(0), v(0);
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		std::sort(graph[i].begin(), graph[i].end());
	}

	memset(depthVec, -1, sizeof(depthVec));
	BFS(R);

	long long result(0);
	for (int i = 1; i <= N; i++)
	{
		result += (depthVec[i] * visitNum[i]);
	}
	std::cout << result << "\n";
	return 0;
}