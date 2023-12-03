#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze2 피보나치 수 - 구현 알고리즘
/// 메모이제이션 기법을 통해 문제를 해결한다.
/// </summary>

vector<long long> fiboVec;

void Fibo(int n)
{
	if (n == 0 || n == 1)
	{
		return;
	}

	for (int i = 2; i <= n; i++)
	{
		fiboVec[i] = fiboVec[i - 1] + fiboVec[i - 2];
	}
}
int main(void)
{
	FastIO;
	int n = 0; // 45보다 작은 수 n
	cin >> n;

	fiboVec.resize(n + 1, 0);
	fiboVec[0] = 0;
	fiboVec[1] = 1;

	Fibo(n);
	cout << fiboVec[n] << "\n";
	return 0;
}