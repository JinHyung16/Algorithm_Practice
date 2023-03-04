#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 Ʈ�� ��ȸ - Graph �˰���
/// �ش� ���� �� ���� �ڽ� ��带 �־��ֱ� ���� struct�� ���
/// ���� ��ȸ�� ��Ʈ -> ���� �ڽ� -> ������ �ڽ� ������ ���
/// ���� ��ȸ�� ���� �ڽ� -> ��Ʈ -> ������ �ڽ� ������ ���
/// ���� ��ȸ�� ���� �ڽ� -> ������ �ڽ� -> ��Ʈ ������ ����Ѵ�.
/// </summary>

using namespace std;


struct Node
{
	char left;
	char right;
};


int N(0); //���� Ʈ���� ����� ���� N
Node node[26];

void Preorder(char root)
{
	if (root == '.')
	{
		return;
	}
	std::cout << root;
	Preorder(node[root].left);
	Preorder(node[root].right);
}

void Inorder(char root)
{
	if (root == '.')
	{
		return;
	}
	Inorder(node[root].left);
	std::cout << root;
	Inorder(node[root].right);
}

void Postorder(char root)
{
	if (root == '.')
	{
		return;
	}
	Postorder(node[root].left);
	Postorder(node[root].right);
	std::cout << root;
}

int main(void)
{
	FastIO;

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		char mid, right, left;
		std::cin >> mid >> left >> right;
		node[mid].left = left;
		node[mid].right = right;
	}

	Preorder('A');
	std::cout << "\n";
	Inorder('A');
	std::cout << "\n";
	Postorder('A');
	std::cout << "\n";

	return 0;
}