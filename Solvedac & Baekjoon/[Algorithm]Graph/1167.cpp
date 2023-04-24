#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold2 트리의 지름 - Graph 알고리즘
/// DFS를 이용한 풀이다.
/// Node struct은 현재 노드에서 연결된 노드와, 해당 노드까지와의 거리를 담고 있는다.
/// 
/// 1) DFS를 이용해 방문하지 않은 곳이면, 먼저 거리가 0일때를 가정해 maxNode를 찾는다.
/// 2) 그 후 maxNode에서 가장 거리가 먼 것을 찾는다.
/// 
/// 예시를 통한 해설
/// 1번 노드 -> 3번 노드로 연결되어 있다. 3번 노드는 1번과 4번노드에 연결되어 있다.
/// 4번 노드는 2번, 3번, 5번 노드와 연결되어 있다.
/// 이렇게 한 노드가 여러 노드의 연결되어 있을 때, 거리가 가장 먼 것을 찾아야하기 때문이다.
/// 따라서 1번 노드에서 시작해 거리가 가장 먼 노드의 번호는 5번 노드다.
/// 이 5번 노드를 찾았으면 1번에서 5번까지의 최대 거리를 알아야하므로 한번 더 DFS를 실행한다.
/// </summary>

using namespace std;

struct Node
{
	int connected; //연결된 노드 정보
	int distance; //연결된 노드 까지와의 거리
};

vector<Node> graph[100000];
vector<bool> visited(100000, false);
int maxNode(0), maxDistance(0);

void ResetVisited()
{
	for (int i = 0; i < visited.size(); i++)
	{
		visited[i] = false;
	}
}
void DFS(int node, int dist)
{
	if (visited[node])
	{
		return;
	}

	if (maxDistance < dist)
	{
		maxDistance = dist;
		maxNode = node;
	}
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++)
	{
		int nextNode = graph[node][i].connected;
		int nextDist = graph[node][i].distance;
		DFS(nextNode, nextDist + dist);
	}
}

int main(void)
{
	FastIO;

	int V(0); //정점이 개수 V
	std::cin >> V;

	int start(0), end(0), distance(0);

	for (int i = 0; i < V; i++)
	{
		std::cin >> start;
		while (true)
		{
			std::cin >> end;
			if (end == -1) 
			{
				break;
			}
			std::cin >> distance;
			graph[start].push_back({ end, distance });
			graph[end].push_back({ start, distance });
		}
	}

	DFS(1, 0); //거리가 0일때, maxNode를 구하기 위함이다.
	ResetVisited();
	maxDistance = 0;
	DFS(maxNode, 0); //maxNode에서 가장 거리가 먼 것을 찾는다.
	std::cout << maxDistance << "\n";
	return 0;
}