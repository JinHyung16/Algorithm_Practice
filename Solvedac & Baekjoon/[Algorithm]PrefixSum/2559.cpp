#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 수열 - 누적합 알고리즘
/// 누적합을 위해, prefix[i]의 이전 값을 더해서 계속 넣어둔다.
/// 그 후 i = K to N해서 result의 prefix[i] - prefix[i-K]값을 넣는다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, K = 0; //온도를 측정한 전체 날짜 N, 합을 구하기 위한 연속적인 날짜 K
	std::cin >> N >> K;
	vector<int> prefix(N + 1, 0);
	int result = 0;

	for ( int i = 1; i <= N; i++ )
	{
		int input = 0;
		std::cin >> input;
		prefix[i] = prefix[i - 1] + input;
	}

	for ( int i = K; i <= N; i++ )
	{
		result = std::max(result, prefix[i] - prefix[i - K]);
	}
	std::cout << result << "\n";
	return 0;
}