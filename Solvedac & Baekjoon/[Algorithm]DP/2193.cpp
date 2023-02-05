#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 이친수 - DP 알고리즘
/// dp[i]는 i길이의 이친수 개수를 담고있다.
/// N=1 이친수 1개
/// N=2 이친수 1개
/// N=3 이친수 2개
/// N=4 이친수 3개
/// N=5 이친수 5개
/// N=6 이친수 8개
/// dp[i] = dp[i-1] + dp[i-2]이다.
/// dp 벡터를 int로하면 수가 커지면 범위를 초과한다. 그러니 long long으로 선언하자
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	
	int N(0); //N자리 이친수
	std::cin >> N;

	vector<long long>dp(91);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	std::cout << dp[N] << "\n";
	return 0;
}