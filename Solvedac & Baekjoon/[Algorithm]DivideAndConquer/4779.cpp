#include<iostream>
#include<vector>
#include<string>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 칸토어 집합 - 분할 정복 알고리즘
/// 문자열은 주어진 N에 대해 3^N 길이다.
/// 먼저 N이 0이면 -을 출력한다.
/// 그 후 분할 정복 + 재귀를 통해 (N-1)을 진행한다.
/// 그러면서 3^N-1개의 맞춰 "-"대신 " "을 출력한다.
/// </summary>

using namespace std;

void DivideAndConquer(int n)
{
	int stringSize = std::pow(3, n - 1);

	if ( n == 0 )
	{
		std::cout << "-";
		return;
	}

	DivideAndConquer(n - 1); //좌측 계산
	for ( int i = 0; i < stringSize; i++ )
	{
		std::cout << " ";
	}
	DivideAndConquer(n - 1); //우측 계산
}

int main(void)
{
	FastIO;

	int N = 0; //주어진 3^N
	while ( std::cin >> N )
	{
		DivideAndConquer(N);
		std::cout << "\n";
	}
	return 0;
}