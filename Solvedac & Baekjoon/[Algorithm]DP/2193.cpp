#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ��ģ�� - DP �˰���
/// dp[i]�� i������ ��ģ�� ������ ����ִ�.
/// N=1 ��ģ�� 1��
/// N=2 ��ģ�� 1��
/// N=3 ��ģ�� 2��
/// N=4 ��ģ�� 3��
/// N=5 ��ģ�� 5��
/// N=6 ��ģ�� 8��
/// dp[i] = dp[i-1] + dp[i-2]�̴�.
/// dp ���͸� int���ϸ� ���� Ŀ���� ������ �ʰ��Ѵ�. �׷��� long long���� ��������
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	
	int N(0); //N�ڸ� ��ģ��
	std::cin >> N;

	vector<long long>dp(91);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	std::cout << dp[N] << "\n";
	return 0;
}