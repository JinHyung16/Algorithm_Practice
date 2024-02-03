#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 방학 숙제 - 구현 알고리즘
/// </summary>


int main(void)
{
	FastIO;

	// 방학 L, 국어 A, 수학 B 하루 최대 국어 C 수학 D
	int L = 0, A = 0, B = 0, C = 0, D = 0;
	
	cin >> L;
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;
	
	int korean = A / C;
	A %= C;
	if ( 0 < A )
		korean++;

	int math = B / D;
	B %= D;
	if ( 0 < B )
		math++;


	if ( korean < math )
		cout << L - math << "\n";
	else
		cout << L - korean << "\n";


	return 0;
}