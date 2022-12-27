#include<iostream>
#include<vector>

/// <summary>
/// Gold4 타일 코드 - DP 알고리즘
/// 대칭 기준을 판단해야한다.
/// n이 홀수일 때, 중간의 2*1 세로 긴 막대기 중심으로 좌우 대칭인 dp[n/2]더하기
/// A+2B형식을 A+B로 바꾸기 위해 A를 더해서 2로 나누는 형식
/// n이 짝수일 때, 2*1 세로 긴 막대기 기준 좌우 대칭 dp[n/2]와 가운데 정사각형 둔 dp[(n-2)/2] 경우
/// 그리고 2*1짜리를 가로로 눕힌 dp[(n/2-1)] * 2한 경우
/// </summary>

using namespace std;

const int MAX_INT = 1000000000;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n(0); //2*N 크기의 타일에서 N의미
	std::cin >> n;

	vector<int> dp(31); //1<= N <= 30이라
	dp[0] = 1;
	dp[1] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		dp[i] += dp[i - 1];
		dp[i] += dp[i - 2] * 2;
	}

	if (n % 2 == 1)
	{
		std::cout << (dp[n] + dp[n / 2]) / 2 << std::endl;
	}
	else
	{
		std::cout << (dp[n] + dp[n / 2] + (2 * dp[n / 2 - 1])) / 2 << std::endl;
	}
	return 0;
}