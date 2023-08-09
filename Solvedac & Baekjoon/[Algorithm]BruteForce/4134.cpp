#include<iostream>
#include<vector>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 다음 소수 - 브루트포스 알고리즘
/// n에 대해 소수 판단시, n의 약수들의 곱은 n의 제곱근일 기준으로 대칭
/// 따라서 sqrt(n) 이하의 값 까지만 검사를 진행하면 된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int T = 0; //테스트 케이스
	long long n = 0;
	long long primeCnt = 0, num = 0; //소수 개수 primeNum, num = sqrt(n) + 1

	std::cin >> T;
	for ( int t = 0; t < T; t++ )
	{
		std::cin >> n;
		bool isPrimeNum = (n < 3) ? true : false;
		primeCnt = (n < 3) ? 2 : n;
		while ( !isPrimeNum )
		{
			num = sqrt(n) + 1;
			for ( int i = 2; i <= num; i++ )
			{
				if ( n % i == 0 )
				{
					break;
				}
				if ( i == num )
				{
					primeCnt = n;
					isPrimeNum = true;
				}
			}
			n++;
		}
		std::cout << primeCnt << "\n";
	}
	return 0;
}