#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 병사 배치하기 - DP 알고리즘
/// '가장 길게 증가하는 부분 수열 문제' 와 동일하다.
/// 왜냐면 주어진 병사를 수열이라 생각하면,
/// 전투력 순서대로 내림차순 하여 가장 긴 부분 수열을 만들면 되기 때문이다.
/// </summary>

int main(void)
{
	FastIO;

	int N = 0; //N명의 병사
	cin >> N;

	vector<int> solider(N + 1, 0);
	vector<int> dp(N + 1, 1);

	for (int i = 0; i < N; i++)
	{
		cin >> solider[i];
	}
	
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (solider[i] < solider[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int maxLength = 0;
	for (int i = 0; i < N; i++)
	{
		maxLength = max(maxLength, dp[i]);
	}

	cout << N - maxLength << "\n";
	
	return 0;
}