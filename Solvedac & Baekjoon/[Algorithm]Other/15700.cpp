#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 타일 채우기 4 - 구현 알고리즘
/// </summary>


int main(void)
{
	FastIO;

	long long N = 0, M = 0; // N * M 크기 벽
	cin >> N >> M;

	cout << (N * M) / 2 << "\n";

	return 0;
}