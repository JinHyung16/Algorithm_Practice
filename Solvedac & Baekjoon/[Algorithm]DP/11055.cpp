#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 가장 큰 증가하는 부분 수열 - DP 알고리즘
/// dp[i]에 sequence[i]를 넣고, 2중 for문을 통해 dp[i] = dp의 이전값과 dp의 이전값 + sequence 현재값 중 큰 값을 넣는다.
/// </summary>

using namespace std;

vector<int> dp;

int main(void)
{
	FastIO;

	int N = 0; //수열 A의 크기
	std::cin >> N;

	vector<int> sequence(N, 0);
	dp.resize(N, 0);

	int result = 0;

	for(int i = 0; i < N; i++)
	{
		std::cin >> sequence[i];
	}

	for(int i = 0; i < N; i++)
	{
		dp[i] = sequence[i];
		for(int j = 0; j < i; j++)
		{
			if(sequence[j] < sequence[i])
			{
				dp[i] = std::max(dp[i], dp[j] + sequence[i]);
			}
		}
		result = std::max(result, dp[i]); //dp[i]에서 가장 큰 값을 넣는다.
	}

	std::cout << result << "\n";
	return 0;
}