#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

/// <summary>
/// Silver2 DFS�� BFS - BFS Graph �̷�
/// DFS�� stack�̿��ϸ�, startNode�� �������� �� �������� �켱 �� �����鼭 �ִ´�.
/// BFS�� queue�� �̿��ϸ�, startNode ������ ���� ���������� ���� ���̴�
/// stack�� ��������, queue�� ���Լ����̴�.
/// �迭 �ʱ�ȭ�� c++���� fill_n ������ �̿�����
/// </summary>

int nodeCount(0), edgeCount(0);
vector<vector<int>> tree(1002, vector<int>(1002, 0)); //�� ��尡 ����Ǿ��ִ��� 1�� 0���� ǥ��
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
	//BFS�� ���� ���������� �湮���� üũ
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