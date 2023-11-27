#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 팩토리얼 2 - 수학 알고리즘
/// vector를 만들어서 메모이제이션 기법을 사용한다.
/// </summary>


int main(void)
{
	FastIO;

	int N = 0; // 0보다 크거나 같은 정수 N
	cin >> N;

	vector<long long> facto(N + 1, 0);
	facto[0] = 1;
	facto[1] = 1;
	facto[2] = 2;
	for ( int i = 3; i <= N; i++ )
	{
		facto[i] = facto[i - 1] * i;
	}
	cout << facto[N] << "\n";
	return 0;
}