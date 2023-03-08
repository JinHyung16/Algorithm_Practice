#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 �ĵ��� ���� - DP �˰���
/// �������� �־��� P(1)~P(10)�� ���� 1,1,1,2,2,3,4,5,7,9�̴�.
/// ��Ģ�� ����, P(4)=P(1)+P(2) / P(5)= P(2)+P(3) / P(6)=P(3)+P(4)��
/// ���� P(N) = P(N-2) + P(N-3)�� �������� �Űܼ� �ذ��ϸ� �ȴ�.
/// </summary>

using namespace std;

long long SolveDP(int N)
{
	vector<long long> dp(101, 0);
	dp[0] = 0, dp[1] = 1, dp[2] = 1;

	if (N < 3)
	{
		return dp[N];
	}

	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}
	return dp[N];
}

int main(void)
{
	FastIO;
	int T(0); //�׽�Ʈ ���̽��� ���� T
	int N(0); //�� ���� ���̰� N�� ���ﰢ��

	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		std::cin >> N;
		std::cout << SolveDP(N) << "\n";
	}
	return 0;
}