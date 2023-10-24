#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 떡 먹는 호랑이 - DP 알고리즘
/// 첫 째날에 준 떡 A개
/// 둘 째날에 준 떡 B개
/// 셋 째날에 준 떡 A+B개
/// 넷 째날에 준 떡 A+2B개
/// 다셋 째날에 준 떡 2A+3B개
/// 
/// 즉 D번째 날에 준 떡의 계수는 (D-3)A + (D-2)B다.
/// 즉 앞의 계수를 정확히 알아야 구할 수 있는 피보나치 수열 문제
/// 
/// A[a]=b는 a번째날 호랑이에게 준 떡의 계수를 구할 때 계수 b
/// B[a]=b는 a번째날 호랑이에게 준 떡의 계수를 구할 때 계수 b
/// 즉 첫 째날에 호랑이에게 준 떡은 이 계수를 이용하면 1A+0B=A
/// 둘 째날에 호랑이에게 준 떡은 이 계수를 이용하면 0A+1B=B
/// ...D번째 날 A[D]=A[D-1]+A[D-2], B[D]=B[D-1]+B[D-2]
/// 
/// 예시는 6번째 날로 3A+5B = 41을 만족해야 하므로
/// A=1이면, 5B = 38로 모듈러 연산을 통해 나눠 떨어지는지 확인한다 
/// </summary>


int main(void)
{
	FastIO;

	int D = 0, K = 0; //넘어온 날 D, 준 떡의 개수 K
	cin >> D >> K;
	vector<int> A(D + 1, 0);
	vector<int> B(D + 1, 0);

	A[1] = 1, A[2] = 0;
	B[1] = 0, B[2] = 1;
	
	for ( int i = 3; i <= D; i++ )
	{
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}

	for ( int i = 1; i <= K; i++ )
	{
		int mod = K - (A[D] * i);
		if ( mod % B[D] == 0 )
		{
			cout << i << "\n" << mod / B[D] << "\n";
			break;
		}
	}
	return 0;
}