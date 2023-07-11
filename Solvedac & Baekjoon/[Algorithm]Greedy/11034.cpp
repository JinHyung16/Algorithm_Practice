#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 캥거루 세마리2 - Greedy 알고리즘
/// 바깥쪽 두 캥거루 중 한 마리가 다른 두 캥거루 사이의 정수 좌표로 점프한다.
/// 따라서 B-A 과 C-B 값 중 큰 값을 찾는다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int A = 0, B = 0, C = 0;

	while ( std::cin >> A >> B >> C )
	{
		int result = std::max(B - A, C - B);
		std::cout << result - 1 << "\n";
	}
	return 0;
}