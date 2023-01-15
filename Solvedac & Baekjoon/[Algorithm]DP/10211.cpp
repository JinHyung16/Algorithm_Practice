#include<iostream>
#include<vector>

/// <summary>
/// Silver4 Maximum Subarray - DP �˰���
/// dp[i]�� i��° ���� �����ϴ� �κ� ������ �ִ� �� �ǹ�
/// int max�� ������ �� ������ -1�� �Ǿ��� �� �������� ���� (������ ���� �����ؼ�)
/// </summary>

using namespace std;

vector<int> dp(1001, 0);
vector<int> vec(1001, 0);

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int testCase(0);
	std::cin >> testCase;

	while (testCase--)
	{
		int N(0); //�迭�� ũ�� N
		std::cin >> N;

		int maxValue = -987654321;

		for (int i = 1; i <= N; i++)
		{
			std::cin >> vec[i];

			dp[i] = std::max(dp[i - 1] + vec[i], vec[i]);
			maxValue = std::max(dp[i], maxValue);
		}

		std::cout << maxValue << std::endl;
	}
	return 0;
}