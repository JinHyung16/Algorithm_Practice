#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ���� �ڸ��� - �̺�Ž�� �˰���
/// ���� ���� �� ������ ������ ���� ���� ������ �ڸ� �� �ִ� �������� �ڸ���.
/// �ڸ��� ���̸� �����ϸ鼭 ������ ���������� ���� ���̿� �񱳸� �ϰ�,
/// ���� ���� ���ڸ��ٸ� end�� mid���� 1�� �����鼭 �ڸ� �� �ִ� �������� �÷�����.
/// ���� ���������� ���̸� �ʰ��ߴٸ� start�� mid���� 1�� ���ϸ鼭 ������ �� �ִ� ������ �ٿ����鼭 ���ܱ⿡ ������ �ִ� ���̸� ã�ư���.
/// 
/// �����Ұ� ���� ���õ� ���ܱ� ����(mid)�� �ڸ��� �� �� ���� ������ ���̵� ������ intŸ������ �ϸ� �ȵȴ�.
/// �켱 �־��� ������ ���� �ִ밪�� ���� ���� ������ �ſ� ������ �� �ִ밪�̸� int�� ����⿡ long long���� ����
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0), M(0); //������ ��N, ������ ���������� ������ ���� M
	std::cin >> N >> M;

	vector<int> treeVec(N, 0);
	int maxHeight(0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> treeVec[i];
	}

	int start(0), end(0);
	for (int i = 0; i < N; i++)
	{
		end = std::max(end, treeVec[i]);
	}

	while (start <= end)
	{
		long long curTreeHeight = 0; //���� ���õ� ���ܱ� ����(mid)�� �ڸ��� �� �� ���� ������ ���̵� ����
		int mid = (start + end) / 2;
		for (int i = 0; i < N; i++)
		{
			if (mid < treeVec[i])
			{
				curTreeHeight += (treeVec[i] - mid);
			}
		}
		if (curTreeHeight < M)
		{
			end = mid - 1;
		}
		else
		{
			maxHeight = mid;
			start = mid + 1;
		}
	}

	std::cout << maxHeight << "\n";
	return 0;
}