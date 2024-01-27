#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 나는 행복합니다~ - 구현 알고리즘
/// 세로 N, 가로 M 크기 배열을 만들어 해결하면 메모리 초과가 날 수 있다.
/// 규칙을 보면 (x, y) 위치를 찾기 위해
/// x = (K / M), y = (K % M)임을 알 수 있다.
/// </summary>


int main(void)
{
	FastIO;

	int N = 0, M = 0, K = 0; // 관중석 크기 N*M, 관중석 번호 K
	cin >> N >> M >> K;

	int x = (K / M);
	int y = (K % M);
	cout << x << " " << y << "\n";
	return 0;
}