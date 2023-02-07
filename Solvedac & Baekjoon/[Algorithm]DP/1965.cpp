#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 상자넣기 - DP 알고리즘
/// dp[i]는 i번째까지 담을 수 있는 최대의 상자 개수 의미
/// 마지막 maxBoxCnt출력시 1개 작게나오니 +1하자
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	vector<int> dp(10001, 0);
	vector<int> box(1001, 0);

	int N(0); //상자의 개수 N
	int maxBoxCnt(0); //넣을 수 있는 최대의 상자 개수

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> box[i];
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (box[j] < box[i])
			{
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
			maxBoxCnt = std::max(dp[i], maxBoxCnt);
		}
	}

	std::cout << maxBoxCnt + 1 << "\n";
	return 0;
}