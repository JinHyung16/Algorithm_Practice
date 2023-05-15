#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 알고리즘 수업, 너비 우선 탐색 3 - Graph 알고리즘
/// 
/// 1. 무방향 그래프라 했으므로, 2차원 배열을 만들고 두 정점 u와 v에 대해 서로 연결시켜 놓는다.
/// 2. depth를 저장하는 배열을 만들고 초기 값은 -1로 세팅해둔다. 왜냐면 방문되지 않은 노드의 깊이는 -1이라 했기에
///	   depth 저장과 동시에 방문 여부를 체크하도록 실행한다.
/// 3. BFS를 돌면서, start 시점의 depth는 0이며 현재 노드에서 연결된 노드에 다 가보면서 만약 깊이가 -1이면 방문하지 않았으므로
///    해당 지점의 방문하면서 depth값은 출발한 지점의 depth값의 + 1을 해주면서 저장한다.
/// </summary>

using namespace std;

vector<int> unDirectedGraph[100001];
vector<int> depthVec(100001, -1);

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	depthVec[start] = 0; //시작 노드의 깊이는 0
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < unDirectedGraph[cur].size(); i++)
		{
			int next = unDirectedGraph[cur][i];
			if (depthVec[next] == -1)
			{
				depthVec[next] = depthVec[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	FastIO;

	int N(0), M(0), R(0); //정점의 수  N, 간선의 수 M, 시작 정점 R
	std::cin >> N >> M >> R;
	for(int i = 1; i <= M; i++)
	{
		int u(0), v(0); //정점 u와 v
		std::cin >> u >> v;
		unDirectedGraph[u].push_back(v);
		unDirectedGraph[v].push_back(u);
	}

	BFS(R);
	for (int i = 1; i <= N; i++)
	{
		std::cout << depthVec[i] << "\n";
	}
	return 0;
}