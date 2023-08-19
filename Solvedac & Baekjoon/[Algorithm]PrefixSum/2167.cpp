#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 2차원 배열의 합 - 누적합 알고리즘
/// 문제에서 보면  x <= N, y <= M으로 배열의 순서가 [y][x]가 아닌 [x][y]다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0, M = 0; //배열의 크기 N, M
	int K = 0; //합을 구할 부분의 개수 K
	std::cin >> N >> M;

	vector<vector<long long>> prefix(N + 1, vector<long long>(M + 1, 0));
	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= M; j++ )
		{
			std::cin >> prefix[i][j];
			prefix[i][j] += prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
		}
	}
	std::cin >> K;
	for ( int k = 0; k < K; k++ )
	{
		int i = 0, j = 0, x = 0, y = 0;
		std::cin >> i >> j >> x >> y;
		std::cout << prefix[x][y] - prefix[i - 1][y] - prefix[x][j - 1] + prefix[i - 1][j - 1] << "\n";
	}
	return 0;
}