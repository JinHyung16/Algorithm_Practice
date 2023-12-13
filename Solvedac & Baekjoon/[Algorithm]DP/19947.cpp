#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver5 투자의 귀재 배주형 - DP 알고리즘
/// 1년에 5% = 1.05
/// 3년에 20% = 1.20f
/// 5년에 35% = 1.35f
/// dp[i]는 항상 1년마다 이자를 계산한다.
/// 그리고 i가 3년 5년이 됐을 때마다 이전 i-1에서 1년 이자와
/// 각 3년 5년전 즉 i-3과 i-5때에서 해당 이자가 붙었을 때의 큰 값을 비교하여 넣는다.
/// 
/// 
/// </summary>


int main(void)
{
	FastIO;
	
	int H = 0, Y = 0; // 초기 비용 H, 투자 기간 Y
	cin >> H >> Y;
	vector<int> dp(Y + 1, 0);

	dp[0] = H;
	for ( int i = 1; i <= Y; i++ )
	{
		dp[i] = (int)(dp[i - 1] * 1.05);
		if ( 3 <= i )
			dp[i] = max((int)dp[i], (int)(dp[i - 3] * 1.2));
		if ( 5 <= i )
			dp[i] = max((int)dp[i], (int)(dp[i - 5] * 1.35));
	}

	cout << (int) dp[Y] << "\n";
	return 0;
}