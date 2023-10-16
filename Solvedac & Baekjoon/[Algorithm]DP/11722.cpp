#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 가장 긴 감소하는 부분 수열 - DP 알고리즘
/// dp[i] = j는 i번 index까지의 최대 길이는 j를 의미한다.
/// 
/// ex) A = {10, 20, 10, 20, 20, 10}을 보면
/// for i=0 to A.size();
///  for j=0 to i;
/// 이런 식의 이중 for문을 돌면서
/// if(배열[i] < 배열[j] && dp[i] < dp[j]+1)
///  dp[i] = dp[j]+1을 해준다.
/// </summary>




int main(void)
{
	FastIO;

	int N = 0; //수열 A의 크기 N
	vector<int> A, dp;
	
	cin >> N;
	A.resize(N, 0);
	dp.resize(N, 0);
	for ( int i = 0; i < N; i++ )
	{
		cin >> A[i];
	}

	for ( int i = 0; i < N; i++ )
	{
		dp[i] = 1;
		for ( int j = 0; j < i; j++ )
		{
			if ( A[i] < A[j] && dp[i] < dp[j] + 1 )
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	sort(dp.rbegin(), dp.rend());
	cout << dp[0] << "\n";
	return 0;
}