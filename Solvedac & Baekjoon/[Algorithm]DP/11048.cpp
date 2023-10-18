#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 이동하기 - DP 알고리즘
/// map[i][j] = b는 맵의 (j,i) 좌표에 있는 사탕 개수.
/// dp[i][j] = a는 (j, i) 좌표에서 지금까지 얻은 사탕의 최대 개수 a를 의미
/// 
/// ex)(3,3)의 위치에 있는 사탕의 개수의 최대 값은
/// (2,3) vs (3,2) vs (2,2)의 수 증 가장 큰 값 + (3,3)의 있는 사탕 개수다.
/// dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + map[i][j]; 다
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0, M = 0; //N*M 크기의 미로
	cin >> N >> M;
	vector<vector<int>> map(N + 1, vector<int>(M + 1, 0));
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= M; j++ )
		{
			cin >> map[i][j];
			dp[i][j] = map[i][j]; //초기 dp[i][j]는 초기 맵에 있는 사탕 개수 그대로다.
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