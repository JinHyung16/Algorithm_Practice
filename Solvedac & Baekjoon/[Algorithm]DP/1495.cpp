#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver1 ��Ÿ����Ʈ - DP �˰���
/// �������� ������ �� i�� ���� P+V[i]�� P-V[i]�����ؾ� �ϳ� 0�̻�, M���Ͽ��� �Ѵٰ� �ߴ�
/// �̰� �̿��ؼ� Ǯ��!
/// �̶� ���� �����ؾ��ϴµ�, M�� 1�̻� 1000���Ϸ� 1001��, n�� 1�̻� 50���Ϸ� 51�� ����
/// ���� ������ 0�̻� M���Ϸ� ������ �˳��ϰ� ��������!
/// </summary>

vector<int> volume(110);
vector<vector<int>>dp(110, vector<int>(1001, 0));

void FindMaxVolume(int n, int s, int m)
{
	if (s + volume[0] <= m)
	{
		dp[0][s + volume[0]] = 1;
	}
	if (0 <= s - volume[0])
	{
		dp[0][s - volume[0]] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i - 1][j] == 1)
			{
				if (j + volume[i] <= m)
				{
					dp[i][j + volume[i]] = 1;
				}
				if (0 <= j - volume[i])
				{
					dp[i][j - volume[i]] = 1;
				}
			}
		}
	}

	for (int i = m; 0 <= i; i--)
	{
		if (dp[n][i] == 1)
		{
			std::cout << i << std::endl;
			return;
		}
	}

	std::cout << -1 << std::endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n(0), s(0), m(0); //���� ����, ���� ����, �ִ� ����
	std::cin >> n >> s >> m;

	for (int i = 0; i < n; i++)
	{
		std::cin >> volume[i];
	}
	FindMaxVolume(n, s, m);

	return 0;
}