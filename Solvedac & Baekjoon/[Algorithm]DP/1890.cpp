#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 점프 - DP 알고리즘
/// dp[i][j] = a는 (j,i)번째에 올 수 있는 경우의 수 개수 a다.
/// 오른쪽과 아래로만 움직일 수 있으니
/// map[i][j]에서 움직일 수 있는 거리를 가져와 moveDis에 넣는다.
/// i + moveDis는 아래로 j + moveDis는 오른쪽으로 움직이는 걸 의미한다.
/// 이렇게 dp의 값을 채워간다.
/// </summary>


int main(void)
{
	FastIO;

	int N = 0; //게임 판의 크기 N
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