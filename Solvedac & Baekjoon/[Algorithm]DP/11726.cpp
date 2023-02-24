#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 2*n Ÿ�ϸ� - DP �˰���
/// dp[i]�� 2*i ũ���� Ÿ���� ä�� �� �ִ� ����� �� % 10007 ���� �ǹ�
/// N�� ���� ��Ģ�� ���� ã�ƺ���.
/// N=1 �̸� ����� �� 1��
/// N=2 �̸� ����� �� 2��
/// dp[N-1] = 2*(N-1)�� 1*2 Ÿ���� ����� ����
/// dp[N-2] = 2*(N-2)�� 2*1 Ÿ���� ����� ����
/// N=3�̸� dp[3] = dp[2] + dp[1]�̵ǹǷ� 3�̴�.
/// ���� dp[i] = dp[i-1] + dp[i-2]��
/// </summary>

using namespace std;

const int divisorNum = 10007;

int main(void)
{
	FastIO;

	int N(0); // 2*N ũ���� ���簢��
	std::cin >> N;

	vector<int> dp(N + 1, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % divisorNum;
	}

	std::cout << dp[N] << "\n";
	return 0;
}