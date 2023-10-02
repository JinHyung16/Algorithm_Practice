#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 줄 세우기 - Graph 알고리즘
/// 위상정렬로 해결하면 된다. 따라서 사이클이 없는 그래프여만 가능
/// 학생 번호 A, B가 순서대로 들어오는데 이는 A가 B앞에 서야하니
/// 방향상 A->B인 그래프가 된다.
/// inDegree 배열은 간선이 들어가는 쪽의 값을 +1 해준다.
/// 즉 A, B이면 그래프 방향이 A->B이니 inDegree[B]++다.
/// 그 후 for i to N까지 돌면서 inDegree에 값이 없음 queue에 추가해준다.
/// !queue.empty()까지 돈다. queue.empty()면 사이클이 생긴것으로 종료한다.
/// </summary>

using namespace std;
vector<vector<int>> graph(32001);
int inDegree[32001]; //위상 정렬에 사용될 진입 차수 배열
vector<int> topologySortVec; //위상 정렬 후 순서에 맞춰 담을 배열

void TopologySort(int N)
{
	queue<int> q;

	for ( int i = 1; i <= N; i++ )
	{
		if ( !inDegree[i] )
		{
			q.push(i);
		}
	}

	while ( !q.empty() )
	{
		int cur = q.front();
		q.pop();
		topologySortVec.push_back(cur);
		//std::cout << cur << " ";
		for ( int i = 0; i < graph[cur].size(); i++ )
		{
			inDegree[graph[cur][i]]--;
			if ( !inDegree[graph[cur][i]] )
			{
				q.push(graph[cur][i]);
			}
		}
	}
}

int main(void)
{
	FastIO;

	int N = 0, M = 0; //정점의 수 N, 키 비교 횟수 M
	std::cin >> N >> M;
	for ( int i = 0; i < M; i++ )
	{
		int A = 0, B = 0; //두 학생 번호 A, B
		std::cin >> A >> B;
		graph[A].push_back(B);
		inDegree[B]++;
	}

	TopologySort(N);

	for ( int i = 0; i < topologySortVec.size(); i++ )
	{
		std::cout << topologySortVec[i] << " ";
	}
	std::cout << "\n";
	return 0;
}	