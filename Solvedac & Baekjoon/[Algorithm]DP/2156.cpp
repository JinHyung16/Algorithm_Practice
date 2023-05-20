#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ������ �ý� - DP �˰���
/// ������ ������ ���� �� ������ ��������.
/// dp[i]�� i�� ���������� ���� ������ �̰ͱ��� ���Ե� ���̴�.
/// i��° �ܿ����� �ִ���
/// 1. i-3������ �ִ� + i��° �� + i-1��° �� -> i��° ���� ���ôϱ� i-2��° ���� ���� �� ����.
/// 2. i-2������ �ִ� + i��° �� -> i��° ���� ���ôϱ� i-1�� ���� �� ����.
/// 3. i-1������ �ֈ��� -> i��° ���� ������ �ʴ� ����.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //������ ���� ���� N
	std::cin >> N;

	vector<long long> dp(N + 1, 0);
	vector<int> inputVec(N + 1, 0);
	
	for (int i = 1; i <= N; i++)
	{
		std::cin >> inputVec[i];
	}

	dp[1] = inputVec[1];
	dp[2] = inputVec[1] + inputVec[2];
	for (int i = 3; i <= N; i++)
	{
		dp[i] = std::max(inputVec[i] + inputVec[i - 1] + dp[i - 3], std::max(inputVec[i] + dp[i - 2], dp[i - 1]));
	}

	std::cout << dp[N] << "\n";
	return 0;
}