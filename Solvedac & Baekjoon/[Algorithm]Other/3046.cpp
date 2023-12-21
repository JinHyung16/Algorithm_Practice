#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 R2 - 구현 알고리즘
/// 두 수의 평균 s = (r1 + r2)/2다.
/// 그러면 r2 = 2*s - r1 이다;
/// </summary>

int main(void)
{
	FastIO;
	
	int r1 = 0, s = 0; // r1과 s
	cin >> r1 >> s;
	
	int r2 = 0;
	r2 = 2 * s - r1;
	cout << r2 << "\n";
	return 0;
}