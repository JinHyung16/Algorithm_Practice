#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 �Ǻ���ġ �� 1 - DP �˰���
/// ��Ϳ� DP�� �����Ѵ�.
/// �̶� ��ʹ� n == 1�� n == 2�϶� cnt�� ���������ְ�,
/// dp�� �׳� for�� ������ ���������ش�.
/// </summary>

using namespace std;

int recursionCnt = 0;
int dpCnt = 0;
int Recursion(int n)
{
	if ( n == 1 || n == 2 )
	{
		recursionCnt++;
		return 1;
	}
	else
	{
		return Recursion(n - 1) + Recursion(n - 2);
	}
}

int main(void)
{
	FastIO;

	int N = 0;
	std::cin >> N;
	Recursion(N);

	vector<int> dp(N + 1, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for ( int i = 3; i <= N; i++ )
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dpCnt++;
	}

	std::cout << recursionCnt << " " << dpCnt << "\n";
	return 0;
}