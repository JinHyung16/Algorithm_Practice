#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 온라인 판매 - Greedy 알고리즘
/// 내림차순으로 달걀 가격이 큰 순서대로 정렬한다.
/// i번째의 달걀 가격이 채택됐다는 의미는, 해당 달걀을 1번부터 i번째까지의 사람이 살 수 있다는 소리다.
/// 즉 i는 달걀을 사는 사람 수를 의미한다고 생각하자
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0), M(0); //N개의 달걀과 M명의 잠재적인 고객
	std::cin >> N >> M;

	vector<int> eggPrice(M, 0);
	int maxPrice(0), canBuyIndex(0);
	for (int i = 0; i < M; i++)
	{
		std::cin >> eggPrice[i];
	}

	std::sort(eggPrice.begin(), eggPrice.end(), std::greater<>());

	for (int i = 0; i < M; i++)
	{
		if (i < N)
		{
			int maxSalePrice = eggPrice[i] * (i + 1);
			if (maxPrice < maxSalePrice)
			{
				//i는 살 수 있는 사람수로 N보다 클 수 없다, 왜냐면 인당 1개의 달걀만 살 수 있으니
				maxPrice = maxSalePrice;
				canBuyIndex = i;
			}
		}
		else
		{
			break;
		}
	}

	std::cout << eggPrice[canBuyIndex] << " " << maxPrice << "\n";
	return 0;
}