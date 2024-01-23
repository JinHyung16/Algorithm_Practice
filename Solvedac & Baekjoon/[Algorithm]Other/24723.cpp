#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 녹색거탑 - 구현 알고리즘
/// 1부터 5까지 직접 경우의 수를 구해보면
/// 규칙이 보이는데 바로 1층 증가마다 *2 경우의 수가 생긴다.
/// </summary>


int main(void)
{
	FastIO;

	int N = 0; // 녹색 거탑의 높이
	cin >> N;
	vector<int> top(N+ 1, 0);
	top[0] = 0;
	top[1] = 2;
	for ( int i = 2; i <= N; i++ )
	{
		top[i] = top[i - 1] * 2;
	}
	cout << top[N] << "\n";
	return 0;
}