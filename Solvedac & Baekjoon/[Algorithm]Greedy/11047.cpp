#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 동전 0- Greedy 알고리즘
/// 동전을 적게 나눠주려면 우선 큰 금액부터 거슬러준다.
/// 그 후 그리디하게 해결
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0), K(0); //동전의 종류 N, 가치의 합 K
	std::cin >> N >> K;
	vector<int> coinPrice(N, 0);
	int minExchangeCnt(0);

	for (int i = 0; i < N; i++)
	{
		std::cin >> coinPrice[i];
	}

	//값이 큰 동전을 먼저 줄수록 동전의 개수가 적어진다.
	std::sort(coinPrice.begin(), coinPrice.end(), std::greater<>());
	for (int i = 0; i < coinPrice.size(); i++)
	{
		while (true)
		{
			if (K - coinPrice[i] < 0)
			{
				break;
			}
			minExchangeCnt++;
			K -= coinPrice[i];
		}
	}

	std::cout << minExchangeCnt << "\n";
	return 0;
}