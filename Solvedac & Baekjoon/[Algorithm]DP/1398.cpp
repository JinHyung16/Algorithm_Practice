#include<iostream>
#include<vector>

/// <summary>
/// Gold2 ���� ���� - DP �˰���
/// 1���� �����ϰ� 10�� 25���϶� �� ����
/// 10�� n�� �̻��� ������ ��, �ش� �������� �ݾ��� �Ž��� �ִ°� �ּҴ�
/// �̸� �̿��� �̸� 100������ �ؼ� �ּҷ� �� �� �ִ� Ƚ���� ��� �д�.
/// �׷��� 100�̻��� �� �ʿ����? �� �����غ��� ��� ���� �ڸ����� �� 100�� ���� �ڸ�����
/// �ٲ��شٸ� ������ ����!
/// </summary>


using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int testCase(0);

	std::cin >> testCase;
	vector<int> dp(101, 0);
	for (int i = 1; i <= 100; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (0 <= i - 10)
		{
			dp[i] = std::min(dp[i], dp[i - 10] + 1);
		}
		if (0 <= i - 25)
		{
			dp[i] = std::min(dp[i], dp[i - 25] + 1);
		}
	}

	for (int i = 0; i < testCase; i++)
	{
		long long chocoPrice;
		std::cin >> chocoPrice;

		long long exchangeCount(0);
		while(chocoPrice)
		{
			exchangeCount += dp[chocoPrice % 100];
			chocoPrice /= 100;
		}

		std::cout << exchangeCount << std::endl;
	}

	return 0;
}