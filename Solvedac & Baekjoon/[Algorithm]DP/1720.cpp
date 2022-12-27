#include<iostream>
#include<vector>

/// <summary>
/// Gold4 Ÿ�� �ڵ� - DP �˰���
/// ��Ī ������ �Ǵ��ؾ��Ѵ�.
/// n�� Ȧ���� ��, �߰��� 2*1 ���� �� ����� �߽����� �¿� ��Ī�� dp[n/2]���ϱ�
/// A+2B������ A+B�� �ٲٱ� ���� A�� ���ؼ� 2�� ������ ����
/// n�� ¦���� ��, 2*1 ���� �� ����� ���� �¿� ��Ī dp[n/2]�� ��� ���簢�� �� dp[(n-2)/2] ���
/// �׸��� 2*1¥���� ���η� ���� dp[(n/2-1)] * 2�� ���
/// </summary>

using namespace std;

const int MAX_INT = 1000000000;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n(0); //2*N ũ���� Ÿ�Ͽ��� N�ǹ�
	std::cin >> n;

	vector<int> dp(31); //1<= N <= 30�̶�
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