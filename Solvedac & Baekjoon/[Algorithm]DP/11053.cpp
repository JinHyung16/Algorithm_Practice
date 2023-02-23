#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ���� �� �����ϴ� �κ� ���� - DP �˰���
/// dp[i]�� i��°�� ���� �� �κ� ������ ���̸� �ǹ�
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	int N(0); //A�� ũ��
	std::cin >> N;
	vector<int> vecA(N, 0); //���� A
	vector<int> dp(N, 1); //i��°�� �κ� ������ ���̸� ��� �ִµ�, �������� i��° ���̴� �� 1�̴�.
	int maxLength(0);

	for (int i = 0; i < N; i++)
	{
		std::cin >> vecA[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vecA[j] < vecA[i])
			{
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
		maxLength = std::max(maxLength, dp[i]);
	}
	
	std::cout << maxLength << "\n";
	return 0;
}