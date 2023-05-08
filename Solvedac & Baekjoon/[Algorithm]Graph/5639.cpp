#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 이진 검색 트리 - Graph 알고리즘
/// 전위 연산은 루트 -> 왼쪽 -> 오른쪽으로 도는것이다.
/// 따라서 주어진 입력에 대해 루트 이후 루트보다 큰 값이 나오기 전까진 다 왼쪽에 위치해있는 것이다.
/// 
/// 후위 연산은 왼쪽 -> 오른쪽 -> 루트 순으로 돌기에 이 순서대로 재귀 호출한다.
/// 이때 후위 연산을 하더라도, 이미 이진 트리는 왼쪽에 있는 값이 오른쪽 보다 작아야한다.
/// 또한 루트보다 큰 노드는 다 오른쪽에 있어야 하기에 이를 생각하면서 재귀 호출한다.
/// </summary>

using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
};

Node* Add(Node* node, int val)
{
	if (node == nullptr)
	{
		node = new Node();
		node->value = val;
		node->left = node->right = nullptr;
	}
	else if (val <= node->value)
	{
		node->left = Add(node->left, val);
	}
	else
	{
		node->right = Add(node->right, val);
	}
	return node;
}

void PostOrder(Node* node)
{
	//왼쪽 -> 오른쪽 순서대로 순회한다.
	if (node->left != nullptr)
	{
		PostOrder(node->left);
	}
	if (node->right != nullptr)
	{
		PostOrder(node->right);
	}
	std::cout << node->value << "\n";
}

int main(void)
{
	FastIO;

	Node* root = nullptr;

	int value(0);
	
	while (std::cin >> value)
	{
		if (value == EOF)
		{
			break;
		}
		root = Add(root, value);
	}

	PostOrder(root);
	return 0;
}