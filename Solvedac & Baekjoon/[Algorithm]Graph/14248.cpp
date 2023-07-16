#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 점프 점프 - Graph 알고리즘
/// 깊이 우선 탐색으로 문제를 해결한다.
/// visited 벡터를 통해 방문했는지 안했는지 유무를 체크한다.
/// 재귀형식으로 DFS를 실행하여, start + graph[start]로 방문하고 다른 쪽은 start - graph[start]를 진행한다.
/// 그렇게 DFS를 다 진행하고 난 뒤, for i to n을 통해 visited[i]가 true곳의 개수를 파악하여 출력한다.
/// </summary>

using namespace std;

int n = 0; //돌다리의 돌 개수
int s = 0; //출발점 s

vector<int> graph;
vector<bool> visited;

void DFS(int start)
{
	if ( start < 1 || n < start )
	{
		return;
	}
	visited[start] = true;
	DFS(start + graph[start]);
	DFS(start - graph[start]);
}

int main(void)
{
	FastIO;
	std::cin >> n;
	graph.resize(n + 1, 0);
	visited.resize(n + 1, false);
	for ( int i = 1; i <= n; i++ )
	{
		std::cin >> graph[i];
	}
	std::cin >> s;

	DFS(s);

	int result = 0;
	for ( int i = 1; i <= n; i++ )
	{
		if ( visited[i] )
		{
			result++;
		}
	}
	std::cout << result << "\n";
	return 0;
}