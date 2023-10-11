#include<iostream>
#include<vector>
#include<algorithm>


#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 1로 만들기 2 - Graph 알고리즘
/// 그래프 문제인줄 알고 풀었는데 DP였다.
/// dp[i]는 i가 문제에 주어진 연산을 만족하면 가장 적은 연산 횟수를 저장한다.
/// </summary>



int main(void)
{
	FastIO;
	
	vector<int> dp;
	int N = 0; //1로 만들어야 하는 N
	cin >> N;

	for ( int i = 0; i <= N; i++ )
	{
		dp.push_back(i);
	}

	for ( int i = 2; i <= N; i++ )
	{
		if ( i % 2 == 0 )
			dp[i] = min(dp[i], dp[i / 2]);
		if ( i % 3 == 0 )
			dp[i] = min(dp[i], dp[i / 3]);
		dp[i] = min(dp[i], dp[i - 1]) + 1;
	}

	cout << dp[N] - 1 << "\n";

	//경로를 추적해가며 N을 출력한다.
	while ( true )
	{
		if ( N <= 0 ) break;
		cout << N << " ";

		if ( dp[N] == dp[N - 1] + 1 )
		{
			N = N - 1;
		}
		else if ( N % 2 == 0 && dp[N] == dp[N / 2] + 1 )
		{
			N = N / 2;
		}
		else if ( N % 3 == 0 && dp[N] == dp[N / 3] + 1 )
		{
			N = N / 3;
		}
	}
	return 0;
}