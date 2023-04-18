#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 2*n Ÿ�ϸ� 2 - DP �˰���
/// DP�� �ٽ��� ��ȭ���� ���ؾ��Ѵ�.
/// �־��� Ÿ���� 1*2, 2*1, 2*2 �̷��� �ִ�.
/// n=i�϶� dp[i]�� 2*i Ÿ�� ����� ä��� ����� ����
/// n=1�϶� 2*1 -> 2*1 -> 1����
/// n=2�϶� 2*2 -> 2*2 or 1*2 2�� or 2*1 2��-> 1 + 1 + 1 = 3����
/// n=3�϶� 2*3 -> dp[2]�� ä��� ���� 2*1������ 2*1 1����� or 1*2 2�� ��� -> 3 + 1 + 1 = 5����
/// n=4�϶� 2*4 -> dp[3]���ٰ� 2*1�� �߰� or dp[2]�� ��쿡�� ���� 2*2 ���� ä��� ��� -> 5 + 3 + 3 = 11����
/// n=5�϶� 2*5 -> dp[4]���ٰ� 2*1�� �߰� or dp[3]�� ��쿡�� ���� 2*2 ���� ä��� ��� -> 11 + 5 + 5 = 21����
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //2*N�� ũ���� ���簢��
	std::cin >> N;
	vector<int> dp(1001, 0); //������ 10007�� �������� �����Ѵ�.
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= N; i++)
	{
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
	}

	std::cout << dp[N] << "\n";
	return 0;
}