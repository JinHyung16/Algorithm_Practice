#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 �̵��ϱ� - DP �˰���
/// map[i][j] = b�� ���� (j,i) ��ǥ�� �ִ� ���� ����.
/// dp[i][j] = a�� (j, i) ��ǥ���� ���ݱ��� ���� ������ �ִ� ���� a�� �ǹ�
/// 
/// ex)(3,3)�� ��ġ�� �ִ� ������ ������ �ִ� ����
/// (2,3) vs (3,2) vs (2,2)�� �� �� ���� ū �� + (3,3)�� �ִ� ���� ������.
/// dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + map[i][j]; ��
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0, M = 0; //N*M ũ���� �̷�
	cin >> N >> M;
	vector<vector<int>> map(N + 1, vector<int>(M + 1, 0));
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= M; j++ )
		{
			cin >> map[i][j];
			dp[i][j] = map[i][j]; //�ʱ� dp[i][j]�� �ʱ� �ʿ� �ִ� ���� ���� �״�δ�.
		}
	}

	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= M; j++ )
		{
			int maxCandy = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
			dp[i][j] = maxCandy + map[i][j];
		}
	}

	cout << dp[N][M] << "\n";

	return 0;
}