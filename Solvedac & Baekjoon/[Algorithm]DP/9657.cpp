#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver3 돌 게임 3 - DP 알고리즘
/// 돌을 1개 3개 4개 가져올 수 있다.
/// dp[i-1], dp[i-3], dp[i-4]가 1이면 상근이가 승리, 0이면 패배로 가정한다.
/// </summary>

int main(void)
{
	FastIO;

	int N = 0; //탁자 위에 있는 돌 N개
	cin >> N;

	vector<int> dp(N + 1, 0);
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= N; i++)
	{
		if (min({ dp[i - 1], dp[i - 3], dp[i - 4] }) == 1)
			dp[i] = 0;
		else
			dp[i] = 1;
	}

	if (dp[N] == 1)
		cout << "SK" << "\n";
	else
		cout << "CY" << "\n";
	return 0;
}