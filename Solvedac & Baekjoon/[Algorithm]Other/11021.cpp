#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 A+B-7 - 구현 알고리즘
/// 단순 문제에 맞춰 사고하여 알고리즘을 푼다.
/// </summary>

int main(void)
{
	FastIO;

	int test_Num = 0;
	int a = 0, b = 0;
	cin >> test_Num;

	for ( int i = 0; i < test_Num; i++ )
	{
		cin >> a >> b;
		cout << "Case #" << (i + 1) << ": " << (a + b) << '\n';
	}
	return 0;
}