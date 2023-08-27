#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 �Ǽ� - DP �˰���
/// dp[i]�� i���� ����� �Ǽ��ϴ� ����.
/// 1�϶� 1, 2�϶� 2, 3�϶� 3, 4�϶� 5��
/// dp[i] = dp[i-1] + dp[i-2]��. �������� ������ ���� ����Ѵ� ������ % 10�� ���ش�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int n = 0; //ȸ�ǿ� ������ �� n
	
	std::cin >> n;
	vector<long long> dp(n + 1, 0);
	dp[0] = 0, dp[1] = 1, dp[2] = 2;
	for ( int i = 3; i <= n; i++ )
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
	}
	std::cout << dp[n] << "\n";
	return 0;
}