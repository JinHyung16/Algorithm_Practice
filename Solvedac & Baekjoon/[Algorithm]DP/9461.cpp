#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 파도반 수열 - DP 알고리즘
/// 문제에서 주어진 P(1)~P(10)의 값은 1,1,1,2,2,3,4,5,7,9이다.
/// 규칙을 보면, P(4)=P(1)+P(2) / P(5)= P(2)+P(3) / P(6)=P(3)+P(4)다
/// 따라서 P(N) = P(N-2) + P(N-3)을 수식으로 옮겨서 해결하면 된다.
/// </summary>

using namespace std;

long long SolveDP(int N)
{
	vector<long long> dp(101, 0);
	dp[0] = 0, dp[1] = 1, dp[2] = 1;

	if (N < 3)
	{
		return dp[N];
	}

	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}
	return dp[N];
}

int main(void)
{
	FastIO;
	int T(0); //테스트 케이스의 개수 T
	int N(0); //그 변의 길이가 N인 정삼각형

	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		std::cin >> N;
		std::cout << SolveDP(N) << "\n";
	}
	return 0;
}