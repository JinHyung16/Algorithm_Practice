#include<iostream>
#include<vector>

/// <summary>
/// Gold2 동전 문제 - DP 알고리즘
/// 1원을 제외하고 10원 25원일때 잘 보면
/// 10의 n승 이상인 단위일 땐, 해당 단위에서 금액을 거슬러 주는게 최소다
/// 이를 이용해 미리 100원까지 해서 최소로 줄 수 있는 횟수를 담아 둔다.
/// 그러면 100이상일 땐 필요없나? 잘 생각해보면 사실 단위 자리수를 다 100과 같은 자릿수로
/// 바꿔준다면 문제가 없다!
/// </summary>


using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int testCase(0);

	std::cin >> testCase;
	vector<int> dp(101, 0);
	for (int i = 1; i <= 100; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (0 <= i - 10)
		{
			dp[i] = std::min(dp[i], dp[i - 10] + 1);
		}
		if (0 <= i - 25)
		{
			dp[i] = std::min(dp[i], dp[i - 25] + 1);
		}
	}

	for (int i = 0; i < testCase; i++)
	{
		long long chocoPrice;
		std::cin >> chocoPrice;

		long long exchangeCount(0);
		while(chocoPrice)
		{
			exchangeCount += dp[chocoPrice % 100];
			chocoPrice /= 100;
		}

		std::cout << exchangeCount << std::endl;
	}

	return 0;
}