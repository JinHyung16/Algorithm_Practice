#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 평범한 배낭 - DP 알고리즘
/// dp[i][j]는 물건 무게 i일때 해당 물건의 가치 j를 의미
/// 무게를 담아놓는 배열을 만들고, 무게 1부터 시작해서 N까지 넣을 수 있나 다 본다.
/// 넣을 수 있다면, 이전 무게 물건의 가치(dp[i-1][j])와 이전 물건에서 넣은 물건의 가치값을 비교해 더 큰 값을 넣는다.
/// 넣을 수 없다면, dp[i][j]는 그냥 이전 무게 물건의 가치를 넣는다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0), K(0); //물품의 수 N, 버틸 수 있는 무게 K
	//int W(0), V(0); //각 물건의 무게 W, 해당 물건의 가치 V

	//vector들을 0으로 초기화하면 각 vector의 0번째 index는 알아서 0으로 할당됨
	vector<vector<int>> dp(101, vector<int>(100001, 0));
	vector<int> weighVec(101, 0);
	vector<int> valueVec(101, 0);

	std::cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> weighVec[i] >> valueVec[i];
	}

	for (int w = 1; w <= N; w++)
	{
		for (int v = 1; v <= K; v++)
		{
			if (0 <= v - weighVec[w])
			{
				//가방에 물건을 넣을 수 있다면
				dp[w][v] = std::max(dp[w - 1][v], dp[w - 1][v - weighVec[w]] + valueVec[w]);
			}
			else
			{
				dp[w][v] = dp[w - 1][v];
			}

		}
	}

	std::cout << dp[N][K] << "\n";
	return 0;
}