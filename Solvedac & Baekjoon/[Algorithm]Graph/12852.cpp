#include<iostream>
#include<vector>
#include<algorithm>


#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 1�� ����� 2 - Graph �˰���
/// �׷��� �������� �˰� Ǯ���µ� DP����.
/// dp[i]�� i�� ������ �־��� ������ �����ϸ� ���� ���� ���� Ƚ���� �����Ѵ�.
/// </summary>



int main(void)
{
	FastIO;
	
	vector<int> dp;
	int N = 0; //1�� ������ �ϴ� N
	cin >> N;

	for ( int i = 0; i <= N; i++ )
	{
		dp.push_back(i);
	}

	for ( int i = 2; i <= N; i++ )
	{
		if ( i % 2 == 0 )
			dp[i] = min(dp[i], dp[i / 2]);
		if ( i % 3 == 0 )
			dp[i] = min(dp[i], dp[i / 3]);
		dp[i] = min(dp[i], dp[i - 1]) + 1;
	}

	cout << dp[N] - 1 << "\n";

	//��θ� �����ذ��� N�� ����Ѵ�.
	while ( true )
	{
		if ( N <= 0 ) break;
		cout << N << " ";

		if ( dp[N] == dp[N - 1] + 1 )
		{
			N = N - 1;
		}
		else if ( N % 2 == 0 && dp[N] == dp[N / 2] + 1 )
		{
			N = N / 2;
		}
		else if ( N % 3 == 0 && dp[N] == dp[N / 3] + 1 )
		{
			N = N / 3;
		}
	}
	return 0;
}