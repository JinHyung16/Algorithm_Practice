#include<iostream>
#include<vector>

/// <summary>
/// Silver4 연속부분최대곱 - DP 알고리즘
/// 실수를 이용하다 보니 int가 아닌 double에 한다.
/// cout에서 반올림을 위한 fixed와
/// 소수점 3자리까지만 출력하는 percision을 기억하자
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N(0); //나열된 양의 실수들의 개수 N
	vector<double> dp(10000, 0.0);
	std::cin >> N;
	vector<double> vec(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> vec[i];
	}

	double maxDouble = 0.0;
	dp[0] = vec[0];

	for (int i = 1; i < N; i++)
	{
		dp[i] = std::max(vec[i], vec[i] * dp[i - 1]);
		maxDouble = std::max(maxDouble, dp[i]);
	}
	
	std::cout << fixed;
	std::cout.precision(3);
	std::cout << maxDouble << std::endl;
	return 0;
}