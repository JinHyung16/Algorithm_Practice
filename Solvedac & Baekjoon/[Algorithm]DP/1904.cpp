#include<iostream>
#include<vector>

/// <summary>
/// Silver3 01타일 - DP 알고리즘
/// 1 단독 또는 00으로 타일을 사용해 만들 수 있다.
/// i번째 타일 개수 = i-1의 개수 + i-2의 개수다.
/// dp는 개수에서 15746으로 나눈 나머지 값을 저장한 것
/// </summary>

using namespace std;

const int divideNum = 15746;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N(0); //길이가 N인 2진수
	std::cin >> N;

	vector<int> dp(1000000, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % divideNum;
	}

	std::cout << dp[N] << std::endl;
	return 0;
}