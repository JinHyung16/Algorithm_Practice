#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ���� ū �����ϴ� �κ� ���� - DP �˰���
/// dp[i]�� sequence[i]�� �ְ�, 2�� for���� ���� dp[i] = dp�� �������� dp�� ������ + sequence ���簪 �� ū ���� �ִ´�.
/// </summary>

using namespace std;

vector<int> dp;

int main(void)
{
	FastIO;

	int N = 0; //���� A�� ũ��
	std::cin >> N;

	vector<int> sequence(N, 0);
	dp.resize(N, 0);

	int result = 0;

	for(int i = 0; i < N; i++)
	{
		std::cin >> sequence[i];
	}

	for(int i = 0; i < N; i++)
	{
		dp[i] = sequence[i];
		for(int j = 0; j < i; j++)
		{
			if(sequence[j] < sequence[i])
			{
				dp[i] = std::max(dp[i], dp[j] + sequence[i]);
			}
		}
		result = std::max(result, dp[i]); //dp[i]���� ���� ū ���� �ִ´�.
	}

	std::cout << result << "\n";
	return 0;
}