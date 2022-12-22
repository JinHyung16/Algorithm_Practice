#include<iostream>
#include<vector>

/// <summary>
/// Silver2 안녕 - DP 알고리즘
/// dp에는 [현재까지 만난 사람의 수][인사를 하며 지금까지 잃은 체력]을 저장하는데
/// 이는 지금까지 얻은 기쁨의 최댓값이되게한다.
/// </summary>


using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n(0);
	vector<int> healthDown(21);
	vector<int> happyGet(21);
	healthDown[0] = 0;
	happyGet[0] = 0;
	vector<vector<int>> dp(21, vector<int>(101, 0)); //n은 최대 20, 기쁨과 체력은 최대 100


	int myHealth = 100;
	int myHappy = 0;

	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		std::cin >> healthDown[i];
	}
	for (int i = 1; i <= n; i++)
	{
		std::cin >> happyGet[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= myHealth; j++)
		{
			if (j + healthDown[i] < myHealth)
			{
				//인사가 가능한 경우, 인사하지 않은경우와 인사한 경우 중 최댓값 비교해서 가져온다
				//현재 잃은 체력이 아직 포함되지 않은 이전 최대 기쁨에 대해 저장
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j + healthDown[i]] + happyGet[i]);
			}
			else
			{
				//인사 불가능한 경우, 원래값과 이전값 중 최댓값 가져온다
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
			}

			if (myHappy < dp[i][j])
			{
				myHappy = dp[i][j];
			}
		}
	}

	std::cout << myHappy << std::endl;

	return 0;
}