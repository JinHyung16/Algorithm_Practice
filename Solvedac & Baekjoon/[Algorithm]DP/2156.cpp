#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 포도주 시식 - DP 알고리즘
/// 연속한 세잔을 마실 수 없음을 주의하자.
/// dp[i]는 i가 마지막으로 마신 잔으로 이것까지 포함된 양이다.
/// i번째 잔에서의 최댓값은
/// 1. i-3까지의 최댓값 + i번째 잔 + i-1번째 잔 -> i번째 잔을 마시니깐 i-2번째 잔은 마실 수 없다.
/// 2. i-2까지의 최댓값 + i번째 잔 -> i번째 잔을 마시니깐 i-1은 마실 수 없다.
/// 3. i-1까지의 최댒값 -> i번째 잔을 마시지 않는 경우다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //포도주 잔의 개수 N
	std::cin >> N;

	vector<long long> dp(N + 1, 0);
	vector<int> inputVec(N + 1, 0);
	
	for (int i = 1; i <= N; i++)
	{
		std::cin >> inputVec[i];
	}

	dp[1] = inputVec[1];
	dp[2] = inputVec[1] + inputVec[2];
	for (int i = 3; i <= N; i++)
	{
		dp[i] = std::max(inputVec[i] + inputVec[i - 1] + dp[i - 3], std::max(inputVec[i] + dp[i - 2], dp[i - 1]));
	}

	std::cout << dp[N] << "\n";
	return 0;
}