#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 ���� (Small) - DP �˰���
/// ���� ū ��ſ��� ��� ���ؼ� �и��ϴ� �� ž�� ���̰� ���ų� 1���̰� �����Ѵ�.
/// dp[i]�� ������ i���϶� ��ſ� ���̴�.
/// dp[0] = 0, dp[1] = 0, dp[2] = 1�̴�.
/// int value ���� ������ i / 2�� �ְ�
/// dp[i] = ((i-value) * value) + dp[i-value] + dp[value];
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //�������� ���� N
	std::cin >> N;
	vector<int> dp(N + 1, 0);
	dp[0] = 0, dp[1] = 0, dp[2] = 1;
	for ( int i = 3; i <= N; i++ )
	{
		int value = i / 2;
		dp[i] = ((i- value) * value) + dp[i - value] + dp[value];
	}
	std::cout << dp[N] << "\n";
	return 0;
}