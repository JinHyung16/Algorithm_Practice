#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze5 알고리즘 수업 - 알고리즘의 수행 시간 1 - 시뮬레이션 알고리즘
/// MenOfPassion 알고리즘을 보면, n이 0부터 증가할 때 마다 결국 반환 하는 값은 0 or 1이다.
/// 따라서 n=1부터 시작이므로 항상 1과 0을 반환하면된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int n = 0;
	std::cin >> n;
	std::cout << "1" << "\n" << "0" << "\n";
	return 0;
}