#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 곱셈 - 분할정복 알고리즘
/// 거듭제곱과 관련된 분할은 A^B에 대하여 B를 짝수와 홀수인 경우로 나눈다.
/// B가 짝수면 -> A^B = A^(B/2) * A^(B/2)
/// B가 홀수면 -> A^B = A^(B/2) * A^(B/2 + 1)는 지수 법칙에 따라 A^(B/2) * A^(B/2) * A게 변한다.
/// 문제는 여기에 % C를 해야하므로
/// 모듈러 연산에 의해
/// B가 홀수일땐 (A^(B/2) * A^(B/2) * A) % C = ((A^(B/2) * A^(B/2)) % C ) * A % C다
/// </summary>

using namespace std;

long long C(0); //C로 나눈 나머지 출력

long long MyPow(long long A, long long B)
{
	if (B == 0) { return 1; }
	else if (B == 1) { return A % C; }

	long long temp = MyPow(A, B / 2); //A^(B/2)를 의미
	if (B % 2 == 0)
	{
		return (temp * temp) % C;
	}
	else
	{
		return ((temp * temp) % C) * A % C;
	}
	
}

int main(void)
{
	FastIO;

	long long A(0), B(0); //자연수 A를 B번 곱한다

	std::cin >> A >> B >> C;
	long long remain = MyPow(A, B);
	std::cout << remain << "\n";
	return 0;
}