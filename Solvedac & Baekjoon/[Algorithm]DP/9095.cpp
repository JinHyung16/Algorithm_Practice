#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver3 1,2,3 더하기 - DP 알고리즘
/// 배열을 선언하고, 배열[index]에서 index의 의미 설정이 중요
/// index는 1,2,3을 더해서 해당 index값을 만들때 기준이고
/// 배열[index]는 그 때 개수를 저장해놓은 것이다.
/// </summary>


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int testCase = 0;
	std::cin >> testCase;
	int num = 0;
	for (int i = 0; i < testCase; i++)
	{
		std::cin >> num;
		vector<int> dp(num+1, 0); //dp는 해당 index를 1,2,3을 더해서 만들 수 있는 방법 수 저장
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		
		for (int j = 4; j <= num; j++)
		{
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		std::cout << dp[num] << std::endl;;
	}
	
	return 0;
}