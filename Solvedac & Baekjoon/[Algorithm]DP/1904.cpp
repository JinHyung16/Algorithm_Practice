#include<iostream>
#include<vector>

/// <summary>
/// Silver3 01Ÿ�� - DP �˰���
/// 1 �ܵ� �Ǵ� 00���� Ÿ���� ����� ���� �� �ִ�.
/// i��° Ÿ�� ���� = i-1�� ���� + i-2�� ������.
/// dp�� �������� 15746���� ���� ������ ���� ������ ��
/// </summary>

using namespace std;

const int divideNum = 15746;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N(0); //���̰� N�� 2����
	std::cin >> N;

	vector<int> dp(1000000, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % divideNum;
	}

	std::cout << dp[N] << std::endl;
	return 0;
}