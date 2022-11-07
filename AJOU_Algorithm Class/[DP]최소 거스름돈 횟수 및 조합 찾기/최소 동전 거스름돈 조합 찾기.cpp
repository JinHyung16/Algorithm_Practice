#include<iostream>
#include<vector>

//201821107 �̵���а� ������
using namespace std;

int main(void)
{
	int coinCount(0); //���� ���� �Է¹ޱ�
	int n(0); //���� ���� �Է¹ޱ�
	int k(0); //�Ž��� �� ����

	vector<int> coins;

	std::cin >> coinCount;
	for (int index = 0; index < coinCount; index++)
	{
		std::cin >> n;
		coins.push_back(n);
	}

	// �Ž��� ���� 0�� �ɶ����� �Է¹ޱ�
	while (true)
	{
		std::cin >> k;
		if (k == 0)
		{
			break;
		}

		vector<int> addCoin(k + 1, 0);
		vector<int> dp(k + 1, k); //�迭�� k��(index�� �Ž��� ���̵�) �Ž��� �ֱ� ���� �ּ� ���� ����

		dp[0] = 0;

		for (int i = 1; i <= k; i++)
		{
			for (int j = 0; j < coinCount; j++)
			{
				if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i])
				{
					dp[i] = dp[i - coins[j]] + 1;
					addCoin[i] = coins[j];
				}
			}
		}
		std::cout << "�����ִ� �ּ� Ƚ����: " << dp[k] << std::endl;

		vector<int> coinCheckVec(k * k, 0);
		coinCheckVec[addCoin[k]] = 1;
		int exchangeMoney = k;
		std::cout << addCoin[exchangeMoney] << std::endl;
		for (int a = 0; a < dp[k]; a++)
		{
			exchangeMoney -= addCoin[exchangeMoney];
			if (exchangeMoney <= 0)
			{
				coinCheckVec[k] = 1;
			}
			else 
			{
				coinCheckVec[addCoin[exchangeMoney]] += 1;
			}

		}

		std::cout << "-------------------------------------------------------" << std::endl;
		std::cout << k << ":" << " ";
		for (int a = 0; a < coinCount; a++)
		{
			std::cout << coins[a] << "(" << coinCheckVec[coins[a]] << ")" << " ";
		}
		std::cout << std::endl;
		std::cout << "-------------------------------------------------------" << std::endl;
		
		//���� �Ž������� ���� ����ϱ� ���� �ʱ�ȭ �ʼ�
		coinCheckVec.clear();
		addCoin.clear();
		dp.clear();
	}

	return 0;
}
