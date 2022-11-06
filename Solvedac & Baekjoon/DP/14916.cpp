#include<iostream>
#include<vector>

using namespace std;

/*
* Silver3 - ���� �Ž�����
*/

int main(void)
{
	long long exchangeMoney = 0; //�Ž��� ��

	cin >> exchangeMoney;
	vector<long long> dp(exchangeMoney + 1, exchangeMoney);
	vector<int> coins = { 2, 5 }; //2�� 5������ �Ž��� �ֱ�

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