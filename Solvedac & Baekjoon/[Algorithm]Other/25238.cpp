#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 가희와 방어율 무시 - 구현 알고리즘
/// </summary>


int main(void)
{
	FastIO;

	int a = 0, b = 0; // 몬스터 방어율 a, 유저 방무 b
	cin >> a >> b;

	double defend = a - a * (b / 100.0);
	
	if ( 100 <= defend )
		cout << 0 << "\n";
	else
		cout << 1 << "\n";

	return 0;
}