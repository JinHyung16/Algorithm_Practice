#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 Four Squares - DP 알고리즘
/// dp[i]는 i에 대해 제곱수로 만들 수 있는 최소 개수의 함을 의미
/// 따라서 주어진 n에 대해 dp[n]은 n을 제곱수를 이용해 만들 수 있는 개수 중 최소 개수를 의미한다.
/// n이 1, 4, 9 인 제곱수로 한번에 표현 가능한 수들은 무조건 dp[n]=1이다.
/// 따라서 n보다 작은 제곱수들 중 가장 큰 제곱수를 n에서 빼고 남은 부분에 대해서만 계산한다면 최소 개수가 된다.
/// 
/// 점화식을 구하고자 규칙을 보면 n=10일때 n보다 작은 제곱수는 9, 4, 1이 있는데 이중 가장 큰 제곱수를 선택해 빼면 10-9해서 1이므로 dp[1] + 1하면 2개다
/// n=5일때 이보다 작은 제곱수 중 가장 큰 값은 4로 5-4=1 따라서 dp[1] + 1하면 2다.
/// n=18일때 16이 가장 큰 제곱수로 18-16=2 따라서 dp[2] + 1하면 3이다.
/// 
/// 따라서 주어진 n에 대하여 n보다 작은 제곱수 중 가장 큰 값을 찾아 나온 값의 +1하면 개수가된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //자연수 N
	vector<int> dp(50000, 0);

	std::cin >> N;
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		int minCnt = 98765;
		for (int j = 1; j * j <= i; j++)
		{
			minCnt = std::min(minCnt, dp[i - (j * j)]);
		}
		dp[i] = minCnt + 1;
	}
	std::cout << dp[N] << "\n";

	return 0;
}