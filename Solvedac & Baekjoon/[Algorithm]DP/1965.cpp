#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ���ڳֱ� - DP �˰���
/// dp[i]�� i��°���� ���� �� �ִ� �ִ��� ���� ���� �ǹ�
/// ������ maxBoxCnt��½� 1�� �۰Գ����� +1����
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	vector<int> dp(10001, 0);
	vector<int> box(1001, 0);

	int N(0); //������ ���� N
	int maxBoxCnt(0); //���� �� �ִ� �ִ��� ���� ����

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> box[i];
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (box[j] < box[i])
			{
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
			maxBoxCnt = std::max(dp[i], maxBoxCnt);
		}
	}

	std::cout << maxBoxCnt + 1 << "\n";
	return 0;
}