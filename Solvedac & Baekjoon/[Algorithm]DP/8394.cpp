#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 악수 - DP 알고리즘
/// dp[i]는 i명의 사람이 악수하는 수다.
/// 1일땐 1, 2일땐 2, 3일땐 3, 4일땐 5로
/// dp[i] = dp[i-1] + dp[i-2]다. 문제에서 마지막 수만 출력한다 했으니 % 10을 해준다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int n = 0; //회의에 참석한 수 n
	
	std::cin >> n;
	vector<long long> dp(n + 1, 0);
	dp[0] = 0, dp[1] = 1, dp[2] = 2;
	for ( int i = 3; i <= n; i++ )
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
	}
	std::cout << dp[n] << "\n";
	return 0;
}