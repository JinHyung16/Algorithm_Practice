#include<iostream>
#include<vector>

/// <summary>
/// Silver4 피보나치 수 7 - DP 알고리즘
/// dp에다가 메모나이제이션하면서 저장해두고
/// 문제 조건처럼 나눠서 나머지를 출력하면 된다.
/// 아니면 dp에다가 나머지를 저장해둬 된다.
/// 그렇게 되면 수의 범위는 int로 처리 가능하다.
/// 

using namespace std;

const int divideNum = 1000000007;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	vector<int> dp(1000001);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	int N(0); //주어진 수 N
	std::cin >> N;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % divideNum;
	}

	std::cout << dp[N] << std::endl;
	return 0;
}