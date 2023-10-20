#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 1,2,3 더하기 3 - DP 알고리즘
/// dp[n] = a면 n을 1,2,3을 더해 만들 수 있는 경우의 수 a개를 의미
/// n=0 -> dp[0] = 1 //점화식을 위해 1로 가정
/// n=1 -> dp[1] = 1
/// n=2 -> dp[2] = 2
/// n=3 -> dp[3] = 4
/// n=4 -> dp[4] = 7
/// n=5 -> dp[5] = 13
/// 즉 dp[n] = dp[n-1] + dp[n-2] + dp[n-3]이다.
/// </summary>

const long long moduler = 1000000009;
long long dp[1000001] = { 0, };

int main(void)
{
	FastIO;

	int t = 0; //테스트 케이스 개수 t
	int n = 0; //n을 1, 2, 3의 합으로 나타내기

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;

	for (int i = 5; i <= 1000000; i++)
	{
		dp[i] = (dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]) % moduler;
	}

	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}