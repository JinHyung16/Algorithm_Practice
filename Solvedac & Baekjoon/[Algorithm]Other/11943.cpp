#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 파일 옮기기 - 구현 알고리즘
/// 바구니 2개에서 사과와 오렌지를 옮기니
/// 바구니 A에 사과를 몰아넣는 경우, 바구니 B에 사과를 몰아넣는 경우
/// 두개를 나눠 최소값을 출력하면 된다.
/// 이렇게 하면 오렌지는 알아서 반대쪽으로 나눠지니 따로 할 필요 없다.
/// </summary>


int main(void)
{
	FastIO;

	int a1 = 0, a2 = 0, o1 = 0, o2 = 0;
	cin >> a1 >> o1;
	cin >> a2 >> o2;

	int basketA = 0, basketB = 0;
	basketA = a1 + o2;
	basketB = a2 + o1;
	
	if ( basketA <= basketB )
		cout << basketA << "\n";
	else
		cout << basketB << "\n";
	return 0;
}