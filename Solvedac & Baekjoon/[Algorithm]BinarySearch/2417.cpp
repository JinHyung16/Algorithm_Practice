#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 정수 제곱근 - 이분 탐색 알고리즘
/// 주어진 n에 대해 sqrt(n)을 진행하여 제곱수를 찾는다.
/// 그 후 sqrtNum을 다시 제곱하여 n보다 작으면 sqrtNum을 1 증가시킨 후 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	long long n = 0;
	std::cin >> n;

	long long sqrtNum = 0;
	sqrtNum = std::sqrt(n);

	if ( (sqrtNum * sqrtNum) < n )
	{
		sqrtNum += 1;
	}
	std::cout << sqrtNum << "\n";
	return 0;
}