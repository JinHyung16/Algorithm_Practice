#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ī�� �����ϱ� - DP �˰���
/// Pi�� i�� ����ִ� ī���� ������ ������ �ǹ�
/// ���� dp[i]�� ī�� i���� �� �� �����ؾ��� �ִ� �ݾ��� ��Ƴ����� �ȴ�.
/// 
/// ex) dp[3]�� �ִ��� 3���� ī�带 �� �� �����ؾ��� �ִ� �ݾ��� ��ƾ� �ϹǷ�
/// dp[3] vs dp[3-1] + P1 vs dp[3-2] + P2 vs dp[3-3] + P3 �� �ִ��� ��ƾ��Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //�����Ϸ��� ī���� ���� N
	std::cin >> N;

	//�׻� price[0] = dp[0] = 0
	vector<int> price(N + 1, 0);
	vector<int> dp(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> price[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = std::max(dp[i], dp[i - j] + price[j]);
		}
	}

	std::cout << dp[N] << "\n";
	return 0;
}
