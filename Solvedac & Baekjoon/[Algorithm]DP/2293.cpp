#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 ����1 - DP �˰���
/// ������ �������� 1��, 2��, 5���� �־�������
/// dp[1]�� 1���� ���� �� �ִ� ����� ���� 1��
/// dp[2]�� dp[1]�� ����� �����ٰ� 1���� �߰��ϴ� 2��
/// dp[3]�� 2���� 1���� ���ϴ���, 1���� 2���� ���ϴ���, �ƴϸ� 1���� 3�� ����ϹǷ� 3������.
/// �� dp[i]���� �־��� ������ �̿��� ���� �� �ִ� ����� ������ �� ���س����Ѵ�.
/// dp[i] = dp[i] + dp[i-�־��� ���� �ݾ�] �̵Ǵ°Ŵ�.
/// dp[0]�� 0���� ����� ���� �ƹ��͵� �������� ���� ���� 1������. �������� ġ�� ������ �����ϴ°�
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0), K(0); //������ ���� N, ��ġ�� �� K
	std::cin >> N >> K;

	vector<int> coins(N, 0);	
	vector<int> dp(K + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < N; i++)
	{
		std::cin >> coins[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = coins[i]; j <= K; j++)
		{
			dp[j] = dp[j] + dp[j - coins[i]];
		}
	}

	std::cout << dp[K] << "\n";
	return 0;
}