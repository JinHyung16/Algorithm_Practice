#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Gold5 ȣ�� - DP �˰���
/// DP������ �ٽ��� 1���� ������Ű���� �ϴ� ���� ��ŭ �� ���鼭
/// �� 1���� ����ؼ� �����س��´�.
/// dp�迭�� ũ��� �ø����� C���� �� ���� �ִ밡 1000�̰�,
/// ������� ��� ���� �� ������ �ִ밡 100���� �ΰ��� ���ϸ� 100000�̴�
/// </summary>

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int clientNum = 0; //C�� ������Ű���� ���� ��
	int cities = 0; //ȫ���Ϸ��� ���� �� N

	std::cin >> clientNum >> cities;
	vector<int> client(1001, 0); //���� �� �ִ� ���� ��
	vector<int> cost(20, 0); //�� ���ÿ��� ȫ���� �� ��� ���
	client[0] = 0;
	cost[0] = 0;

	for (int i = 1; i <= cities; i++)
	{
		std::cin >> cost[i] >> client[i];
	}

	vector<int> dp(100001, 0); //������ 100000�ε� �ű⿡ +1���ذŴ�. �� ������ �������� �� �� �ּ� ����
	dp[0] = 0;
	for (int i = 1; i <= cities; i++)
	{
		for (int j = 1; j <= 100000; j++)
		{
			if (j - cost[i] >= 0)
			{
				dp[j] = std::max(dp[j], dp[j - cost[i]] + client[i]);
			}
		}
	}

	for (int i = 1; i <= 100000; i++)
	{
		if (clientNum <= dp[i])
		{
			std::cout << i << "\n";
			break;
		}
	}

	return 0;
}