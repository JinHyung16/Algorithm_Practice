#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 피자 (Small) - DP 알고리즘
/// 가장 큰 즐거움을 얻기 위해선 분리하는 두 탑의 높이가 같거나 1차이가 나야한다.
/// dp[i]는 피자판 i개일때 즐거움 값이다.
/// dp[0] = 0, dp[1] = 0, dp[2] = 1이다.
/// int value 에는 피자판 i / 2를 넣고
/// dp[i] = ((i-value) * value) + dp[i-value] + dp[value];
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //피자판의 개수 N
	std::cin >> N;
	vector<int> dp(N + 1, 0);
	dp[0] = 0, dp[1] = 0, dp[2] = 1;
	for ( int i = 3; i <= N; i++ )
	{
		int value = i / 2;
		dp[i] = ((i- value) * value) + dp[i - value] + dp[value];
	}
	std::cout << dp[N] << "\n";
	return 0;
}