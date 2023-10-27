#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 A+B-8 - 구현 알고리즘
/// 단순 문제에 맞춰 사고하여 알고리즘을 푼다.
/// </summary>

int main(void)
{
	FastIO;

	int T = 0; //테스트 케이스
	int A = 0, B = 0;

	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> A >> B;
		cout << "Case #" << i + 1 << ": " << A << " + " << B << " = " << A + B << "\n";
	}
	return 0;
}