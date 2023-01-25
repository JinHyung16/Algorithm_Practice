#include<iostream>
#include<vector>

/// <summary>
/// Silver4 �Ǻ���ġ �� 7 - DP �˰���
/// dp���ٰ� �޸������̼��ϸ鼭 �����صΰ�
/// ���� ����ó�� ������ �������� ����ϸ� �ȴ�.
/// �ƴϸ� dp���ٰ� �������� �����ص� �ȴ�.
/// �׷��� �Ǹ� ���� ������ int�� ó�� �����ϴ�.
/// 

using namespace std;

const int divideNum = 1000000007;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	vector<int> dp(1000001);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	int N(0); //�־��� �� N
	std::cin >> N;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % divideNum;
	}

	std::cout << dp[N] << std::endl;
	return 0;
}