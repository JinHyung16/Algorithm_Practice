#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver1 기타리스트 - DP 알고리즘
/// 문제에서 제공된 식 i번 곡은 P+V[i]나 P-V[i]연주해야 하나 0이상, M이하여야 한다고 했다
/// 이걸 이용해서 풀자!
/// 이때 범위 조심해야하는데, M은 1이상 1000이하로 1001로, n이 1이상 50이하로 51로 잡자
/// 시작 볼륨이 0이상 M이하로 범위를 넉넉하게 설정하자!
/// </summary>

vector<int> volume(110);
vector<vector<int>>dp(110, vector<int>(1001, 0));

void FindMaxVolume(int n, int s, int m)
{
	if (s + volume[0] <= m)
	{
		dp[0][s + volume[0]] = 1;
	}
	if (0 <= s - volume[0])
	{
		dp[0][s - volume[0]] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i - 1][j] == 1)
			{
				if (j + volume[i] <= m)
				{
					dp[i][j + volume[i]] = 1;
				}
				if (0 <= j - volume[i])
				{
					dp[i][j - volume[i]] = 1;
				}
			}
		}
	}

	for (int i = m; 0 <= i; i--)
	{
		if (dp[n][i] == 1)
		{
			std::cout << i << std::endl;
			return;
		}
	}

	std::cout << -1 << std::endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n(0), s(0), m(0); //곡의 개수, 시작 볼륨, 최대 볼륨
	std::cin >> n >> s >> m;

	for (int i = 0; i < n; i++)
	{
		std::cin >> volume[i];
	}
	FindMaxVolume(n, s, m);

	return 0;
}