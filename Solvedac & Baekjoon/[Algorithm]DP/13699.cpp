#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ��ȭ�� - DP �˰���
/// �־��� ��ȭ���� �̿��� ������ �ذ��Ѵ�.
/// for i=3 <= n
///		for j=1 <= i
///			dp[i] += dp[j - 1] * dp[i - j]
/// ���� ���� �̿��� �ذ��Ѵ�.
/// �̶� ������ �����Ͽ� dp vector�� long long Ÿ������ �����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int n = 0; //t(n)�� ��ȭ��
	std::cin >> n;
	vector<long long> dp(n + 1, 0);
	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for ( int i = 3; i <= n; i++ )
	{
		for ( int j = 1; j <= i; j++ )
		{
			dp[i] += (dp[j - 1] * dp[i - j]);
		}
	}
	std::cout << dp[n] << "\n";
	return 0;
}