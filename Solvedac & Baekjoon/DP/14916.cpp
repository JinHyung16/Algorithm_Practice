#include<iostream>
#include<vector>

using namespace std;

/*
* Silver3 - 동전 거스름돈
*/

int main(void)
{
	long long exchangeMoney = 0; //거스름 돈

	cin >> exchangeMoney;
	vector<long long> dp(exchangeMoney + 1, exchangeMoney);
	vector<int> coins = { 2, 5 }; //2원 5원으로 거슬러 주기

	dp[0] = 0;
	for (int i = 1; i <= exchangeMoney; i++)
	{
		for (int j = 0; j < coins.size(); j++)
		{
			if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i])
			{
				dp[i] = dp[i - coins[j]] + 1;
			}
		}
	}

	if (dp[exchangeMoney] == exchangeMoney)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << dp[exchangeMoney] << endl;
	}

	return 0;
}