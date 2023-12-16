#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 제리와 톰 - 수학 알고리즘
/// 분수 표현이므로 두 번째 입력 - 첫 번째 입력과 두 번째 입력을 출력한다.
/// </summary>

int main(void)
{
	FastIO;

	int A = 0, B = 0; // 두 정수 A, B
	cin >> A >> B;
	cout << B - A << " " << B;
	return 0;
}