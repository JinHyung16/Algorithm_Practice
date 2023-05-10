#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold1 Ʈ���� ��ȸ - ���� ���� �˰���
/// inorder(���� ��ȸ): ���� ��� -> �θ� ��� -> ������ ���
/// postorder(���� ��ȸ): ���� ��� -> ������ ��� -> �θ� ���
/// preorder(���� ��ȸ): �θ� ��� -> ���� ��� -> ������ ���
/// 
/// �Է� �����ſ� ���� �켱 �θ��带 �ľ�����.
/// ���� inorder���� �Է��� ���� ��, tree��� �迭�� tree[inorder[i]] = i�� �����ؼ� tree index�� ���� ���� ������ �����صд�.
/// postorder���� �� �ڿ��ִ� ���� ���� ��Ʈ�̹Ƿ�, �̰� �̿��Ѵ�. 
/// �� �� left�� right���� �ľ��� ���� root - inorder start�� inorder end - root�� �����Ͽ� ���� left�� right������ ã�´�.
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

	int root = tree[postorderVec[po_e]]; //postorder�� �� �ڰ� ��Ʈ
	int left = root - in_s; //root���� inorder�� ó�� �Է¹��� ���� ���� left�� �ִ� ���� �ľ�
	int right= in_e - root; //inorder ������ �Է¹��� ���� right �����̴� root���� ���� right�� �ִ� ���� �ľ�
	std::cout << inorderVec[root] << "\n";
	
	//�� -> �� ������ ã�ƺ���.
	PreOrder(in_s, root - 1, po_s, po_s + left - 1);
	PreOrder(root + 1, in_e, po_s + left, po_e - 1);
}

int main(void)
{
	FastIO;

	int N(0); //n���� ����
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