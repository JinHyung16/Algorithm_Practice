#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold1 트리의 순회 - 분할 정복 알고리즘
/// inorder(중위 순회): 왼쪽 노드 -> 부모 노드 -> 오른쪽 노드
/// postorder(후위 순회): 왼쪽 노드 -> 오른쪽 노드 -> 부모 노드
/// preorder(전위 순회): 부모 노드 -> 왼쪽 노드 -> 오른쪽 노드
/// 
/// 입력 받은거에 대해 우선 부모노드를 파악하자.
/// 먼저 inorder에서 입력을 받을 때, tree라는 배열에 tree[inorder[i]] = i로 저장해서 tree index에 맞춰 들어온 순서를 저장해둔다.
/// postorder에서 맨 뒤에있는 값이 가장 루트이므로, 이걸 이용한다. 
/// 그 후 left와 right영역 파악을 위해 root - inorder start와 inorder end - root를 진행하여 각각 left와 right영역을 찾는다.
/// </summary>

using namespace std;

vector<int> inorderVec(100001, 0);
vector<int> postorderVec(100001, 0);
vector<int> tree(100001, 0);

void PreOrder(int in_s, int in_e, int po_s, int po_e)
{
	if (in_e < in_s || po_e < po_s)
	{
		return;
	}

	int root = tree[postorderVec[po_e]]; //postorder의 맨 뒤가 루트
	int left = root - in_s; //root에서 inorder에 처음 입력받은 값을 빼서 left에 있는 수를 파악
	int right= in_e - root; //inorder 마지막 입력받은 수는 right 영역이니 root에서 빼서 right에 있는 수를 파악
	std::cout << inorderVec[root] << "\n";
	
	//좌 -> 우 순으로 찾아본다.
	PreOrder(in_s, root - 1, po_s, po_s + left - 1);
	PreOrder(root + 1, in_e, po_s + left, po_e - 1);
}

int main(void)
{
	FastIO;

	int N(0); //n개의 정점
	std::cin >> N;

	int input(0);
	for (int i = 1; i <= N; i++)
	{
		std::cin >> inorderVec[i];
	}

	for (int i = 1; i <= N; i++)
	{
		std::cin >> postorderVec[i];
	}

	for (int i = 1; i <= N; i++)
	{
		tree[inorderVec[i]] = i;
	}

	PreOrder(1, N, 1, N);
	return 0;
}