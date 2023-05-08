#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 ���� �˻� Ʈ�� - Graph �˰���
/// ���� ������ ��Ʈ -> ���� -> ���������� ���°��̴�.
/// ���� �־��� �Է¿� ���� ��Ʈ ���� ��Ʈ���� ū ���� ������ ������ �� ���ʿ� ��ġ���ִ� ���̴�.
/// 
/// ���� ������ ���� -> ������ -> ��Ʈ ������ ���⿡ �� ������� ��� ȣ���Ѵ�.
/// �̶� ���� ������ �ϴ���, �̹� ���� Ʈ���� ���ʿ� �ִ� ���� ������ ���� �۾ƾ��Ѵ�.
/// ���� ��Ʈ���� ū ���� �� �����ʿ� �־�� �ϱ⿡ �̸� �����ϸ鼭 ��� ȣ���Ѵ�.
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
	//���� -> ������ ������� ��ȸ�Ѵ�.
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