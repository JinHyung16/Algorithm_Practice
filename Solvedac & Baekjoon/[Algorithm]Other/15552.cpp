#include<iostream>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 빠른 입출력 - 구현 알고리즘
/// </summary>


int main(void)
{
	FastIO;

	int T = 0; // 테스트 케이스 개수 T
	cin >> T;
	int A = 0, B = 0;
	while ( T-- )
	{
		cin >> A >> B;
		cout << A + B << "\n";
	}

	return 0;
}