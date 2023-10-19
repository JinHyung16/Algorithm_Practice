#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 ���� - DP �˰���
/// dp[i][j] = a�� (j,i)��°�� �� �� �ִ� ����� �� ���� a��.
/// �����ʰ� �Ʒ��θ� ������ �� ������
/// map[i][j]���� ������ �� �ִ� �Ÿ��� ������ moveDis�� �ִ´�.
/// i + moveDis�� �Ʒ��� j + moveDis�� ���������� �����̴� �� �ǹ��Ѵ�.
/// �̷��� dp�� ���� ä������.
/// </summary>


int main(void)
{
	FastIO;

	int N = 0; //���� ���� ũ�� N
	cin >> N;
	
	vector<vector<int>> map(N, vector<int>(N, 0));
	vector<vector<long long>> dp(N, vector<long long>(N, 0));

	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < N; j++ )
		{
			cin >> map[i][j];
		}
	}

	dp[0][0] = 1;

	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < N; j++ )
		{
			if ( map[i][j] == 0 ) continue;

			int moveDis = map[i][j];
			if ( i != N - 1 && i + moveDis < N )
			{
				dp[i + moveDis][j] += dp[i][j];
			}
			if ( j != N - 1 && j + moveDis < N )
			{
				dp[i][j + moveDis] += dp[i][j];
			}
		}
	}

	cout << dp[N - 1][N - 1] << "\n";
	return 0;
}