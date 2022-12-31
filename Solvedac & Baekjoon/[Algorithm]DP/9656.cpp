#include<iostream>
#include<vector>

/// <summary>
/// Silver4 �� ���� 2 - DP �˰���
/// ������ ����̰� ���� �����Ѵ�
/// ����� ���� dp[i-1]�� dp[i-3]�� 1�̸� ���� ��Ȳ, 0�̸� �̱�� ��Ȳ�̴�
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int stonN(0); //�� ���� N
	vector<int> dp(1001, 0);

	std::cin >> stonN;
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;

	for (int i = 4; i <= stonN; i++)
	{
		if (std::min(dp[i - 1], dp[i - 3]) == 1) //���� ���� 1�̶�� �ǹ̸� �ľ��ϱ�
		{
			//����� ���� ����̰� �������� ���� ���� 1���� ���� â���̰� ���� �������� ����̰� �̱��
			dp[i] = 0;
		}
		else
		{
			//�ƴϸ� ����̰� �� ��찡 �ȴ�
			dp[i] = 1;
		}
	}

	if (dp[stonN] == 1)
	{
		std::cout << "SK" << std::endl;
	}
	else
	{
		std::cout << "CY" << std::endl;
	}
	return 0;
}