#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 피보나치 수의 확장 - DP 알고리즘
/// 처음 풀었을 때 틀렸다. 이유는 음수쪽에서 발생했다.
/// F(0)=0, F(-1)=1, F(-2)=-1, F(-3)=2, F(-4)=-1
/// 이런식으로 음수에선 절댓값이 짝수면 음수 홀수면 양수로 나왔던 것이다.
/// 
/// F(N)양수면 1, 음수면 -1, 0이면 0 출력하기
/// </summary>

using namespace std;

const int divideNum = 1000000000;

int main(void)
{
	FastIO;
	
	vector<int> dp(1000001);
	dp[0] = 0;
	dp[1] = 1;

	int N(0), input(0);
	std::cin >> input;
	if (input < 0)
	{
		N = input * (-1); //양수로 만들어 주기
	}
	else
	{
		N = input;
	}

	
	for (int i = 2; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % divideNum;
	}

	dp[N] = dp[N] % divideNum;

	if (N == 0)
	{
		std::cout << N << "\n" << N;
		return 0;
	}
	else if (input < 0)
	{
		//음수일때 절대값이 짝수면 음수
		if (N % 2 == 0)
		{
			std::cout << -1 << "\n" << dp[N];
			return 0;
		}
	}

	//양수 또는 음수인데 절대값이 홀수인 경우
	std::cout << 1 << "\n" << dp[N];

	return 0;
}