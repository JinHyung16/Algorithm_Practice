#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 데스 나이트 - Graph 알고리즘
/// 루트 노드는 1이다.
/// 성원이가 이기려면 루트에서 리프까지의 depth를 봐야 하는데
/// 루트에서 모든 리프까지의 depth를 더해서 홀수면 성원이가 이기고 짝수면 성원이가 진다.
/// </summary>


vector<vector<int>> trees;
vector<bool> visited;

int treeTotalDepth = 0;

void DFS(int start, int depth)
{
	if (trees[start].size() == 1 && start != 1)
	{
		treeTotalDepth += depth;
		return;
	}
	for (int i = 0; i < trees[start].size(); i++)
	{
		if (!visited[trees[start][i]])
		{
			visited[trees[start][i]] = true;
			DFS(trees[start][i], depth + 1);
			visited[trees[start][i]] = false;
		}
	}
}

int main(void)
{
	FastIO;

	int N = 0; // 트리의 정점 개수 N
	cin >> N;
	trees.resize(N + 1);
	visited.resize(N + 1, false);

	int a = 0, b = 0; // a와 b 노드 사이의 간선
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		trees[a].push_back(b);
		trees[b].push_back(a);
	}
	visited[1] = true;
	DFS(1, 0);

	if (treeTotalDepth % 2 == 1)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";

	return 0;
}