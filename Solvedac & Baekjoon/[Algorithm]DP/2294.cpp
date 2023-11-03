#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

const int MAX_INT = 987654321;
/// <summary>
/// Gold5 동전 2 - DP 알고리즘
/// n가지의 동전만큼 for문을 돌면서
/// 안쪽 for문에서 가치 k만큼 돈다.
/// dp[i]=a는 i원을 만드는데 최소 경우의 수 a를 의미한다.
/// </summary>

int main(void)
{
	FastIO;

	int n = 0, k = 0; //n가지 종류 동전 개수, 가치의 합 k원
	cin >> n >> k;
	
	vector<int> dp(k + 1, MAX_INT);
	vector<int> coins(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
		dp[coins[i]] = 1;
	}

	for(int i = 0; i < n; i++)
	{
		for (int j = 2; j <= k; j++)
		{
			if (0 < j - coins[i])
			{
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
	}

	if (dp[k] == MAX_INT)
		cout << -1 << "\n";
	else
		cout << dp[k] << "\n";
	return 0;
}