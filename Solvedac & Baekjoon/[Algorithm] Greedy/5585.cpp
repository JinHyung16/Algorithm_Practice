#include<iostream>
#include<vector>
#include<string>


using namespace std;

/// <summary>
/// Bronze2 거스름돈 - Greedy 알고리즘
/// 소유한 거스름돈은 500, 100, 50, 10, 5, 1
/// 가장 최소한으로 거스름돈을 주자
/// 핵심!! 가장 큰 거스름돈 순으로 input을 정렬해놓자
/// 핵심!! 그리디는 최대한 안주려고 욕심부리는 것
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
		//가장 큰 돈 순서대로 최대한 많이 주면서 counting하기
		while (price - exchangeCoins[i] >= 0)
		{
			minCount++;
			price -= exchangeCoins[i];
		}
	}

	std::cout << minCount << std::endl;
	return 0;
}