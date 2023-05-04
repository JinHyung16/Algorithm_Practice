#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 Ʈ���� ���� - Graph �˰���
/// DFS�� �̿��� �ذ��Ѵ�.
/// ���� DFS�� �̿��� start node=1���� ������ �� �ڽ� ��尡 ������� ã�´�.
/// �׷��� end node�� ���� �� �ڽ� ��带 �ְ�, visitied�� �ʱ�ȭ �Ѵ���
/// DFS�� �̿��� end node���� �Ųٷ� �ö���鼭 ������ ���̸� ���Ѵ�.
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

	int N(0); //����� ���� N
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