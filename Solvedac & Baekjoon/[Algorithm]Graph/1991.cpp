#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 트리 순회 - Graph 알고리즘
/// 해당 노드와 좌 우의 자식 노드를 넣어주기 위해 struct을 사용
/// 전위 순회는 루트 -> 왼쪽 자식 -> 오른쪽 자식 순으로 출력
/// 중위 순회는 왼쪽 자식 -> 루트 -> 오른쪽 자식 순으로 출력
/// 후위 순회는 왼쪽 자식 -> 오른쪽 자식 -> 루트 순으로 출력한다.
/// </summary>

using namespace std;


struct Node
{
	char left;
	char right;
};


int N(0); //이진 트리의 노드의 개수 N
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