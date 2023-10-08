#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze1 최소공배수 - 수학 알고리즘
/// 최소 공배수를 찾기 위해선 최대 공약수를 먼저 구한다.
/// 그 후 두 수를 최대 공약수로 각각 나눈 나머지와 최대공약수를 곱한다.
/// </summary>

int GreatDivisor(int a, int b)
{
	if ( a % b == 0 )
		return b;
	else
		return GreatDivisor(b, a % b);
}

int main(void)
{
	FastIO;

	int T = 0; //테스트 케이스 T
	int A = 0, B = 0;
	cin >> T;
	while ( T-- )
	{
		cin >> A >> B;
		if ( B <= A )
			cout << A * B / GreatDivisor(A, B) << "\n";
		else
			cout << A * B / GreatDivisor(B, A) << "\n";
	}
	return 0;
}