#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 이상한 기호 - 구현 알고리즘
/// A@B = (A+B) * (A-B)다.
/// 이를 전개해서 계산하도 되고 아니면 그냥 계산해도 괜찮다.
/// </summary>


long long Calcul(long long a, long long b)
{
	return ((a + b) * (a - b));
}

int main(void)
{
	FastIO;

	long long A = 0, B = 0;
	cin >> A >> B;
	cout << Calcul(A, B) << "\n";
	return 0;
}