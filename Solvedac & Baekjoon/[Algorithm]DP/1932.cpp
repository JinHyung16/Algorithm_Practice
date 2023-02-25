#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 정수 삼각형 - DP 알고리즘
/// (i,j)를 기준으로 본인 위의 어디 부분에 값이 있고 무엇을 가져올지 상각하면서 푼다.
/// 그렇게 조건에 맞춰 if문을 만들어 해결한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //삼각형의 크기 N
	std::cin >> N;
	vector<vector<int>>dp(N + 5, vector<int>(N + 5, 0));

	dp[0][0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			std::cin >> dp[i][j];
		}
	}

	int maxSum = dp[1][1];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i + 1; j++)
		{
			if (j == 1)
			{
				//이 경우는 내 바로 위만 값이 있으므로 해당 부분만 값을 가져온다.
				dp[i][j] += dp[i - 1][j];
			}
			else if (j == i)
			{
				//이 경우는 내 위쪽에서 왼쪽 부분만 값이 있으므로 해당 부분만 값을 가져온다.
				dp[i][j] += dp[i - 1][j - 1];
			}
			else
			{
				//그 외는 바로위 또는 왼쪽 대각선에서 값을 가져온다
				dp[i][j] += std::max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
			maxSum = std::max(dp[i][j], maxSum);
		}
	}

	std::cout << maxSum << "\n";
	return 0;
}