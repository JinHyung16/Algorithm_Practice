#include<iostream>
#include<algorithm>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 영수증 - 수학 알고리즘
/// 변수에 (물건의 가격 * 물건의 개수)를 하나씩 입력받아 더해서 저장해둔다.
/// 그 후 입력받은 영수증 총 금액 X와 비교하여 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int X = 0, N = 0; //총 금액 X, 구매한 물건의 종류 N
	std::cin >> X;
	std::cin >> N;

	int sum = 0; //물건의 가격 * 개수를 총 합해서 저장할 변수
	for ( int i = 0; i < N; i++ )
	{
		int a = 0, b = 0; //물건의 가격 a, 개수 b
		std::cin >> a >> b;
		sum += (a * b);
	}

	if ( sum == X )
		std::cout << "Yes" << "\n";
	else
		std::cout << "No" << "\n";

	return 0;
}	