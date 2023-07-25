#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze5 직사각형 - 수학 알고리즘
/// 직사각형의 넓이는 가로*세로다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int A = 0, B = 0; //세로 길이 Acm, 가로 길이 Bcm
	std::cin >> A >> B;

	std::cout << A * B << "\n";
	return 0;
}