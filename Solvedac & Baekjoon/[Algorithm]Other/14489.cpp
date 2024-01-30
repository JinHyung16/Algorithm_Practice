#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 치킨 두 마리 (...) - 구현 알고리즘
/// </summary>


int main(void)
{
	FastIO;
	
	int A = 0, B = 0; // 두 통장의 잔고 A, B
	int C = 0; // 치킨 한 마리 가격 C
	cin >> A >> B;
	cin >> C;

	if ( (2 * C) <= (A + B) )
		cout << (A + B) - 2 * C << "\n";
	else
		cout << A + B << "\n";

	return 0;
}