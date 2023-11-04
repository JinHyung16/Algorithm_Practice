#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold4 타일 채우기 - DP 알고리즘
/// n=1 -> 0가지
/// n=2 -> 3가지
/// n=3 -> 0가지
/// n=4 -> dp[2]*dp[2] + 2 = 11가지
/// n=5 -> 0가지
/// n=6 -> dp[2]*dp[4] + dp[2]*2 + 2 = 41가지
/// ...
/// dp[n] = dp[n-2]*dp[2] + dp[n-4]*2 + dp[n-6]*2 + ... + 2
/// </summary>

int main(void)
{
	FastIO;

	int N = 0; //3*N 크기의 벽
	cin >> N;
	
	vector<int> dp(N + 1, 0);
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 3; i <= N; i++)
	{
		if (i % 2 != 0)
			dp[i] = 0;
		else
		{
			for (int j = 2; j <= N; j++)
			{
				if (j == 2)
					dp[i] = dp[i - j] * dp[2];
				else if (0 <= i - j)
					dp[i] += dp[i - j] * 2;
			}
		}
	}

	cout << dp[N] << "\n";
	
	return 0;
}