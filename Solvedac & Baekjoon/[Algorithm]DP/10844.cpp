#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���� ��� �� - Graph �˰���
/// ���̰� N�� ��� ���� �ǹ̸� �ľ��غ��� (1 <= N <= 100 ������)
/// N=1 -> 1~9���� �� 9��
/// N=2 -> 10 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98 �� 17��
/// 
/// �� ������ ������ ���� ������ ���� �տ� ���� ����� ���鵵 �޶�����.
/// dp[i][j]�� i������ j�� ������ �������� �����صд�.
/// dp[2][2]�� 2������ 2�� ������ �������� 12�� 32 �� 2����.
/// dp[2][2]�� dp[1][2] + dp[1][3]�� ����� ���� ��ģ ���̴�.
/// 
/// �̶�, 0���� ������ ���� �տ� �� ���� ������ 1 Ŀ���ϰ�, 9�� ������ ���� �տ� �� ���� ������ 1�� �۾ƾ��ϱ⿡ ���� ���Ѵ�.
/// dp[i][0] = dp[i-1][i+1]�̰�, dp[i][0] = dp[i-1][j-1]�̴�.
/// </summary>

using namespace std;

int mod = 1000000000;

int main(void)
{
	FastIO;

	int N(0); //��ܼ��� ����
	std::cin >> N;

	vector<vector<int>> dp(101, vector<int>(101, 0));
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][0] = dp[i - 1][j + 1];
			}
			else if (j == 9)
			{
				dp[i][9] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			dp[i][j] %= mod;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result = (result + dp[N][i]) % mod;
	}
	std::cout << result << "\n";
	return 0;
}
