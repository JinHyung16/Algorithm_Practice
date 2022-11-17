#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver5 �迭 ��ġ�� - ���� �˰���
/// �������� ���������� sort�ؾ� �ϴ� c++�� sort�� O(nlogn)���� �̸� �̿�����
/// ������ std::cin�� std::cout�� �ð��� �� �ɷ��� printf, scanf���� �ƴϸ�
/// �� ��� �ӵ� up ��Ű�°� �ʿ��ϴ�
/// </summary>


int main(void)
{
	//�� ��� �ӵ� up
	ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int aSize = 0, bSize = 0;
	std::cin >> aSize >> bSize;

	int totalSize = aSize + bSize;
	vector<int> totalVec(totalSize);

	for (int i = 0; i < totalSize; i++)
	{
		std::cin >> totalVec[i];
	}

	std::sort(totalVec.begin(), totalVec.end());

	for (int i = 0; i < totalVec.size(); i++)
	{
		std::cout << totalVec[i] << " ";
	}
	return 0;
}