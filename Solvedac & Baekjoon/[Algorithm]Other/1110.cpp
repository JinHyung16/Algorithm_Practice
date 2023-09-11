#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 더하기 사이클 - 구현 알고리즘
/// 십과 일의 자리로 나누고, 일의 자리 + 십의 자리 이후 일의 자리를 다시 십의 자리로 바꿔 넣으면 된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int n, sum;
	int a, b;
	int sycle = 1;
	cin >> n;
	int m = n;

	while ( true )
	{
		a = (n / 10), b = (n % 10);
		sum = a + b;
		n = (b * 10) + (sum % 10);
		if ( m == n )
			break;
		else
			sycle++;
	}
	cout << sycle << endl;

	return 0;
}