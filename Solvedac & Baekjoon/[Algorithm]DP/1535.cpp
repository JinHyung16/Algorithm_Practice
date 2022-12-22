#include<iostream>
#include<vector>

/// <summary>
/// Silver2 �ȳ� - DP �˰���
/// dp���� [������� ���� ����� ��][�λ縦 �ϸ� ���ݱ��� ���� ü��]�� �����ϴµ�
/// �̴� ���ݱ��� ���� ����� �ִ��̵ǰ��Ѵ�.
/// </summary>


using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n(0);
	vector<int> healthDown(21);
	vector<int> happyGet(21);
	healthDown[0] = 0;
	happyGet[0] = 0;
	vector<vector<int>> dp(21, vector<int>(101, 0)); //n�� �ִ� 20, ��ݰ� ü���� �ִ� 100


	int myHealth = 100;
	int myHappy = 0;

	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		std::cin >> healthDown[i];
	}
	for (int i = 1; i <= n; i++)
	{
		std::cin >> happyGet[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= myHealth; j++)
		{
			if (j + healthDown[i] < myHealth)
			{
				//�λ簡 ������ ���, �λ����� �������� �λ��� ��� �� �ִ� ���ؼ� �����´�
				//���� ���� ü���� ���� ���Ե��� ���� ���� �ִ� ��ݿ� ���� ����
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j + healthDown[i]] + happyGet[i]);
			}
			else
			{
				//�λ� �Ұ����� ���, �������� ������ �� �ִ� �����´�
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
			}

			if (myHappy < dp[i][j])
			{
				myHappy = dp[i][j];
			}
		}
	}

	std::cout << myHappy << std::endl;

	return 0;
}