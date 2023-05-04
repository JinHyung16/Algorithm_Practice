#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 트리의 지름 - Graph 알고리즘
/// DFS를 이용해 해결한다.
/// 먼저 DFS를 이용해 start node=1부터 시작해 맨 자식 노드가 어디인지 찾는다.
/// 그래서 end node에 가장 끝 자식 노드를 넣고, visitied를 초기화 한다음
/// DFS를 이용해 end node부터 거꾸로 올라오면서 지름의 길이를 구한다.
/// </summary>

using namespace std;

vector<pair<int, int>> graph[10001];
vector<bool> visited(10001, false);
int endNode(0), result(0);

void DFS(int curNode, int radius)
{
	if (visited[curNode])
	{
		return;
	}
	visited[curNode] = true;
	if (result < radius)
	{
		result = radius;
		endNode = curNode;
	}
	for (int i = 0; i < graph[curNode].size(); i++)
	{
		DFS(graph[curNode][i].first, radius + graph[curNode][i].second);
	}
}

int main(void)
{
	FastIO;

	int N(0); //노드의 개수 N
	std::cin >> N;

	int parent(0), child(0), weight(0);
	for (int i = 0; i < N - 1; i++)
	{
		std::cin >> parent >> child >> weight;
		graph[parent].push_back(make_pair(child, weight));
		graph[child].push_back(make_pair(parent, weight));
	}
	
	DFS(1, 0);
	for (int i = 0; i < visited.size(); i++)
	{
		visited[i] = false;
	}
	DFS(endNode, 0);

	std::cout << result << "\n";
	return 0;
}