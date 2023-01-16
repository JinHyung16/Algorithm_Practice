#include<iostream>
#include<string>
#include<algorithm>

/// <summary>
/// Silver5 피보나치 수 4 - DP 알고리즘
/// dp[i]는 i번째 까지의 피보나치 수를 의미한다.
/// 재귀로 풀면 함수가 스택에 계속 쌓이고, 시간이 오래걸린다.
/// 함수를 이용해 메모나이제이션하면서 풀어보자
/// n의 최대가 10000이므로, 피보나치 계산하면 수가 매우 커진다
/// long long으로 해결하거나 string으로 풀자
/// string으로 더할경우, carry발생까지 체크하면서 계산하자
/// </summary>

using namespace std;

string Fibonacci(string a, string b)
{
	int num(0);
	int carry(0);

	string result;
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());

	while (a.length() != b.length())
	{
		if (a.length() < b.length())
		{
			a += '0';
		}
		else
		{
			b += '0';
		}
	}

	for (int i = 0; i < a.length(); i++)
	{
		num = (a[i] - '0' + b[i] - '0' + carry) % 10;
		result += std::to_string(num);
		carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
	}

	if (carry != 0)
	{
		result += std::to_string(carry);
	}

	std::reverse(result.begin(), result.end());
	return result;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string dp[10010];

	int N(0); //n번째 피보나치 수
	std::cin >> N;
	
	dp[0] = '0';
	dp[1] = '1';

	for (int i = 2; i <= N; i++)
	{
		dp[i] = Fibonacci(dp[i - 1], dp[i - 2]);
	}

	std::cout << dp[N] << std::endl;
	return 0;
}