#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���� ���� Ʈ�� - Ʈ�� �˰���
/// ���� ��ȸ �ϰ� ������, ���� ���� Ʈ���� ���̰� H����� ����� ���� 2^H - 1���� �Ǵ� ������ Ȧ������ ��带 ���´�.
/// ���� root ���� �� ����� ��Ʈ ����.
/// 
/// ��� �Լ��� �̿��� left, right�� ������ ��ȯ�Ѵ�.
/// �������� K�� depth �Ǵ� height�� �����ؼ� �ذ��Ѵ�.
/// </summary>

using namespace std;

int K = 0; //1�̻� 2^K �� �̸��� �湮�� ��� ����
vector<int> trees;
vector<int> result[10]; //K�� �ִ밪�� 10�̹Ƿ�
void PreOrder(int left, int right, int height)
{
	if(height == K)
	{
		//depth��ŭ �� ���Ҵٸ� return
		return;
	}

	if(left == right)
	{
		//left���� �ش� depth�� ����ϰ� return
		result[height].push_back(trees[left]);
		return;
	}

	int midRoot = (left + right) / 2;
	result[height].push_back(trees[midRoot]);
	PreOrder(left, midRoot - 1, height + 1); //���� ��ȯ
	PreOrder(midRoot + 1, right, height + 1); //������ ��ȯ
}

int main(void)
{
	FastIO;
	
	std::cin >> K;

	int maxNode = std::pow(2, K) - 1;
	for(int i = 0; i < maxNode; i++)
	{
		int node = 0;
		std::cin >> node;
		trees.push_back(node);
	}
	
	PreOrder(0, trees.size(), 0);

	for(int i = 0; i < K; i++)
	{
		for(int j = 0; j < result[i].size(); j++)
		{	
			std::cout << result[i][j] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}