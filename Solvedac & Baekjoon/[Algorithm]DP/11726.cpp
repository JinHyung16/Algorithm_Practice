#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 2*n 타일링 - DP 알고리즘
/// dp[i]는 2*i 크기의 타일을 채울 수 있는 방법의 수 % 10007 값을 의미
/// N에 따라 규칙을 먼저 찾아본다.
/// N=1 이면 방법의 수 1개
/// N=2 이면 방법의 수 2개
/// dp[N-1] = 2*(N-1)로 1*2 타일을 사용한 개수
/// dp[N-2] = 2*(N-2)로 2*1 타일을 사용한 개수
/// N=3이면 dp[3] = dp[2] + dp[1]이되므로 3이다.
/// 따라서 dp[i] = dp[i-1] + dp[i-2]다
/// </summary>

using namespace std;

const int divisorNum = 10007;

int main(void)
{
	FastIO;

	int N(0); // 2*N 크기의 직사각형
	std::cin >> N;

	vector<int> dp(N + 1, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % divisorNum;
	}

	std::cout << dp[N] << "\n";
	return 0;
}