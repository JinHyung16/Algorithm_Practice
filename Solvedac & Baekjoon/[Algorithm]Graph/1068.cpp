#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Gold 5 트리 - Graph 알고리즘
/// 주어진 트리가 binary teee인지는 모른다.
/// 그러니 DFS를 이용해 끝까지 탐색해보자
/// </summary>

vector<int> tree[51];
int leaf(0), removeNode(0);

int DFS(int node)
{
	if (node == removeNode)
	{
		return -1;
	}
	if (tree[node].size() <= 0)
	{
		leaf++;
		return 0;
	}
	for (int i = 0; i < tree[node].size(); i++)
	{
		int temp = DFS(tree[node][i]);
		if (temp == -1 && tree[node].size() == 1)
		{
			leaf++;
		}
	}

	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int nodeN(0), root(0);
	std::cin >> nodeN;
	for (int i = 0; i < nodeN; i++)
	{
		int node = 0;
		std::cin >> node;
		if (node == -1)
		{
			//부모가 없는 노드인경우
			root = i;
		}
		else
		{
			tree[node].push_back(i);
		}
	}
	std::cin >> removeNode;
	DFS(root);

	std::cout << leaf << std::endl;
	return 0;
}