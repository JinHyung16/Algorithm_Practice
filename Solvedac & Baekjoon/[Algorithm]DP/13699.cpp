#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 점화식 - DP 알고리즘
/// 주어진 점화식을 이용해 문제를 해결한다.
/// for i=3 <= n
///		for j=1 <= i
///			dp[i] += dp[j - 1] * dp[i - j]
/// 다음 식을 이용해 해결한다.
/// 이때 범위를 주의하여 dp vector는 long long 타입으로 선언한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int n = 0; //t(n)의 점화식
	std::cin >> n;
	vector<long long> dp(n + 1, 0);
	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for ( int i = 3; i <= n; i++ )
	{
		for ( int j = 1; j <= i; j++ )
		{
			dp[i] += (dp[j - 1] * dp[i - j]);
		}
	}
	std::cout << dp[n] << "\n";
	return 0;
}