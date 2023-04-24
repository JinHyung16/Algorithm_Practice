#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold2 Ʈ���� ���� - Graph �˰���
/// DFS�� �̿��� Ǯ�̴�.
/// Node struct�� ���� ��忡�� ����� ����, �ش� ���������� �Ÿ��� ��� �ִ´�.
/// 
/// 1) DFS�� �̿��� �湮���� ���� ���̸�, ���� �Ÿ��� 0�϶��� ������ maxNode�� ã�´�.
/// 2) �� �� maxNode���� ���� �Ÿ��� �� ���� ã�´�.
/// 
/// ���ø� ���� �ؼ�
/// 1�� ��� -> 3�� ���� ����Ǿ� �ִ�. 3�� ���� 1���� 4����忡 ����Ǿ� �ִ�.
/// 4�� ���� 2��, 3��, 5�� ���� ����Ǿ� �ִ�.
/// �̷��� �� ��尡 ���� ����� ����Ǿ� ���� ��, �Ÿ��� ���� �� ���� ã�ƾ��ϱ� �����̴�.
/// ���� 1�� ��忡�� ������ �Ÿ��� ���� �� ����� ��ȣ�� 5�� ����.
/// �� 5�� ��带 ã������ 1������ 5�������� �ִ� �Ÿ��� �˾ƾ��ϹǷ� �ѹ� �� DFS�� �����Ѵ�.
/// </summary>

using namespace std;

struct Node
{
	int connected; //����� ��� ����
	int distance; //����� ��� �������� �Ÿ�
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

	int V(0); //������ ���� V
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

	DFS(1, 0); //�Ÿ��� 0�϶�, maxNode�� ���ϱ� �����̴�.
	ResetVisited();
	maxDistance = 0;
	DFS(maxNode, 0); //maxNode���� ���� �Ÿ��� �� ���� ã�´�.
	std::cout << maxDistance << "\n";
	return 0;
}