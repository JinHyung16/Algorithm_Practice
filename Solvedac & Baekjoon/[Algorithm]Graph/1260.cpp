#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

/// <summary>
/// Silver2 DFS와 BFS - BFS Graph 이론
/// DFS는 stack이용하며, startNode를 시작으로 한 방향으로 우선 다 가보면서 넣는다.
/// BFS는 queue를 이용하며, startNode 인접을 보며 좋은곳으로 가는 것이다
/// stack은 선입후출, queue는 선입선출이다.
/// 배열 초기화시 c++에는 fill_n 있으니 이용하자
/// </summary>

int nodeCount(0), edgeCount(0);
vector<vector<int>> tree(1002, vector<int>(1002, 0)); //두 노드가 연결되어있는지 1과 0으로 표시
vector<bool> visited(1002, false);


void DFS(int start)
{
	stack<int> stk;
	stk.push(start);
	
	while (!stk.empty())
	{
		int curNode = stk.top();
		stk.pop();
		if (!visited[curNode])
		{
			std::cout << curNode << " ";
		}

		visited[curNode] = true;

		for (int i = nodeCount; i > 0; i--)
		{
			if (tree[curNode][i] == 1 && !visited[i])
			{
				stk.push(i);
			}
		}
	}
}

void BFS(int start)
{
	//BFS는 본인 시작점부터 방문으로 체크
	visited[start] = true;

	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();

		std::cout << curNode << " ";

		for (int i = 1; i <= nodeCount; i++)
		{
			if (tree[curNode][i] == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int startNode(0);
	std::cin >> nodeCount >> edgeCount >> startNode;

	int from(0), to(0);
	for (int i = 0; i < edgeCount; i++)
	{
		std::cin >> from >> to;
		tree[from][to] = 1;
		tree[to][from] = 1;
	}

	DFS(startNode);
	std::cout << "\n";

	std::fill_n(visited.begin(), 1002, false);

	BFS(startNode);

	return 0;
}