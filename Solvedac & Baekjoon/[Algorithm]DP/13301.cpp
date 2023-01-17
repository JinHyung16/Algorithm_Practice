#include<iostream>
#include<vector>

/// <summary>
/// Silver5 Ÿ�� ��Ĺ� - DP �˰���
/// dp[i]�� i���� Ÿ�� ��Ĺ� �ѷ� ���̸� ����ִ�
/// dp[1]�� ���� 1¥�� Ÿ�� 1���� �ѷ�
/// dp[2]�� ���� 1¥�� 2���� ��ģ Ÿ���� �ѷ�
/// dp[3]�� ���� 1¥�� 2���� ���� 2¥�� 1�� Ÿ���� ��ģ �ѷ�
/// �⺻�� �Ǻ���ġ ������ ������. �׷��� dp�� ������� �����ϴ��Ŀ� ����
/// ���� �����ϰ� ���� �� �ִ�/
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //Ÿ���� ���� n
	std::cin >> N;

	vector<long long> dp(81);
	dp[0] = 0;
	dp[1] = 4;
	dp[2] = 6;
	dp[3] = 10;
	dp[4] = 16;

	for (int i = 5; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	std::cout << dp[N] << std::endl;
	return 0;
}