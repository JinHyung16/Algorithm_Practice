#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 오르막 수 - DP 알고리즘
/// dp[i][j]는 길이가 i인데 끝자리가 j로 끝나고 앞자리가 j이하인 수의 개수를 의미한다.
/// j	0	1	2	3	4	5	6	7	8	9
/// i=1	1	1	1	1	1	1	1	1	1	1
/// i=2 1	2	3	4	5	6	7	8	9	10
/// i=3 1	3	6	10	15	21	28	36	45	55
/// 
/// j가 0일때를 제외하고 dp[i][j] = dp[i-1][j] + dp[i][j-1]이다
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //수의 길이 N
	std::cin >> N;
	vector<vector<int>> dp(N + 1, vector<int>(10, 0));

	for(int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for(int i = 2; i <= N; i++)
	{
		for(int j = 1; j < 10; j++)
		{
			dp[i][0] = 1; //항상 i길이의 0으로 끝나는 수의 개수는 1개다.
			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007;
		}
	}

	long long result = 0;
	for(int i = 0; i < 10; i++)
	{
		result += dp[N][i];
	}

	std::cout << result % 10007 << "\n";
	return 0;
}