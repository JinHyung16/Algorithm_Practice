#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 피보나치 비스무리한 수열 - DP 알고리즘
/// 4번째 수 부터 규칙을 보면 dp[i] = dp[i-1] + dp[i-3]인걸 볼 수 있다.
/// 이때 범위가 int를 넘으니 long long으로 해결한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int n = 0; //n번째 비스무리한 수
	std::cin >> n;

	vector<long long> dp(n + 10, 0);
	dp[0] = 0, dp[1] = 1, dp[2] = 1, dp[3] = 1;
	for ( int i = 4; i <= n; i++ )
	{
		dp[i] = dp[i - 1] + dp[i - 3];
	}

	std::cout << dp[n] << "\n";
	return 0;
}