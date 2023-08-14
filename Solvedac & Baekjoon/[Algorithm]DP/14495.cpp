#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 �Ǻ���ġ �񽺹����� ���� - DP �˰���
/// 4��° �� ���� ��Ģ�� ���� dp[i] = dp[i-1] + dp[i-3]�ΰ� �� �� �ִ�.
/// �̶� ������ int�� ������ long long���� �ذ��Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int n = 0; //n��° �񽺹����� ��
	std::cin >> n;

	vector<long long> dp(n + 10, 0);
	dp[0] = 0, dp[1] = 1, dp[2] = 1, dp[3] = 1;
	for ( int i = 4; i <= n; i++ )
	{
		dp[i] = dp[i - 1] + dp[i - 3];
	}

	std::cout << dp[n] << "\n";
	return 0;
}