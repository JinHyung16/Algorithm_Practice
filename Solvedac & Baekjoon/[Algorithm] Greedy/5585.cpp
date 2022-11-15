#include<iostream>
#include<vector>
#include<string>


using namespace std;

/// <summary>
/// Bronze2 �Ž����� - Greedy �˰���
/// ������ �Ž������� 500, 100, 50, 10, 5, 1
/// ���� �ּ������� �Ž������� ����
/// �ٽ�!! ���� ū �Ž����� ������ input�� �����س���
/// �ٽ�!! �׸���� �ִ��� ���ַ��� ��ɺθ��� ��
/// </summary>


int main(void)
{
	int payment = 1000;
	int price = 0;
	vector<int> exchangeCoins = { 500, 100, 50, 10, 5, 1 };
	int minCount = 0;

	std::cin >> price;
	price = payment - price;

	for (int i = 0; i < exchangeCoins.size(); i++)
	{
		//���� ū �� ������� �ִ��� ���� �ָ鼭 counting�ϱ�
		while (price - exchangeCoins[i] >= 0)
		{
			minCount++;
			price -= exchangeCoins[i];
		}
	}

	std::cout << minCount << std::endl;
	return 0;
}