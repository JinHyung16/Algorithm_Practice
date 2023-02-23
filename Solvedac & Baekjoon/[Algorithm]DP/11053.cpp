#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 가장 긴 증가하는 부분 수열 - DP 알고리즘
/// dp[i]는 i번째의 가장 긴 부분 수열의 길이를 의미
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	int N(0); //A의 크기
	std::cin >> N;
	vector<int> vecA(N, 0); //수열 A
	vector<int> dp(N, 1); //i번째의 부분 수열의 길이를 담고 있는데, 시작전엔 i번째 길이는 다 1이다.
	int maxLength(0);

	for (int i = 0; i < N; i++)
	{
		std::cin >> vecA[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vecA[j] < vecA[i])
			{
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
		maxLength = std::max(maxLength, dp[i]);
	}
	
	std::cout << maxLength << "\n";
	return 0;
}