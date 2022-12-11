#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Gold 5 Ʈ�� - Graph �˰���
/// �־��� Ʈ���� binary teee������ �𸥴�.
/// �׷��� DFS�� �̿��� ������ Ž���غ���
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
			//�θ� ���� ����ΰ��
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