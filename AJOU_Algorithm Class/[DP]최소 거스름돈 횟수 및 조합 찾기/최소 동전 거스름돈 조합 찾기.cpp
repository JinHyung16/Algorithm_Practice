#include<iostream>
#include<vector>

//201821107 미디어학과 김진형
using namespace std;

int main(void)
{
	int coinCount(0); //동전 개수 입력받기
	int n(0); //동전 유형 입력받기
	int k(0); //거스름 돈 개수

	vector<int> coins;

	std::cin >> coinCount;
	for (int index = 0; index < coinCount; index++)
	{
		std::cin >> n;
		coins.push_back(n);
	}

	// 거스름 돈이 0이 될때까지 입력받기
	while (true)
	{
		std::cin >> k;
		if (k == 0)
		{
			break;
		}

		vector<int> addCoin(k + 1, 0);
		vector<int> dp(k + 1, k); //배열의 k원(index가 거스름 돈이됨) 거슬러 주기 위한 최소 개수 저장

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
		std::cout << "나눠주는 최소 횟수는: " << dp[k] << std::endl;

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
		
		//다음 거스름돈에 대해 계산하기 위해 초기화 필수
		coinCheckVec.clear();
		addCoin.clear();
		dp.clear();
	}

	return 0;
}
