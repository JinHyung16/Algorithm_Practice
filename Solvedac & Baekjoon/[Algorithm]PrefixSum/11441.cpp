#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver3 합 구하기 - 누적합 알고리즘
/// prefixSum[a] = b는 a번째 index까지의 누적합은 b를 의미.
/// 따라서 i, j가 들어왔을 때, 해당 구간의 누적합은
/// prefixSum[j] - prefixSum[i-1]을 해주면 된다.
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0, M = 0;
	vector<int> prefixSum;
	int a = 0, i = 0, j = 0; //i번째 수부터 j번째 수까지의 합
	cin >> N;
	prefixSum.resize(N + 1, 0);
	for ( int i = 1; i <= N; i++ )
	{
		cin >> a;
		prefixSum[i] = prefixSum[i - 1] + a;
	}
	cin >> M;
	while ( M-- )
	{
		cin >> i >> j;
		cout << prefixSum[j] - prefixSum[i - 1] << "\n";
	}

	return 0;
}