#include<iostream>
#include<vector>

/// <summary>
/// Silver4 Maximum Subarray - DP 알고리즘
/// dp[i]는 i번째 수를 포함하는 부분 수열의 최대 합 의미
/// int max를 음수로 쓴 이유는 -1이 되었을 때 뒤집히기 때문 (수열이 음수 포함해서)
/// </summary>

using namespace std;

vector<int> dp(1001, 0);
vector<int> vec(1001, 0);

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int testCase(0);
	std::cin >> testCase;

	while (testCase--)
	{
		int N(0); //배열의 크기 N
		std::cin >> N;

		int maxValue = -987654321;

		for (int i = 1; i <= N; i++)
		{
			std::cin >> vec[i];

			dp[i] = std::max(dp[i - 1] + vec[i], vec[i]);
			maxValue = std::max(dp[i], maxValue);
		}

		std::cout << maxValue << std::endl;
	}
	return 0;
}