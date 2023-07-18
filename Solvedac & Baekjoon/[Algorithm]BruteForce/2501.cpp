#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 약수 구하기 - 브루트포스 알고리즘
/// 약수의 개수를 세는 temp 변수를 선언한다.
/// 약수를 vector에 차례대로 저장한다.
/// vector에 약수에 해당하는 divisor index에 i값을 저장한다.
/// 그 후 K보다 약수 개수가 크거나 같으면 벡터에서 꺼내 출력하고
/// 아니면 0을 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0, K = 0; //N의 약수들 중 K번째로 작은 수
	std::cin >> N >> K;
	
	int divisor = 0;
	int temp = 0;
	vector<int> divisorVec(10000, 0);
	for ( int i = 1; i <= N; i++ )
	{
		if ( (N % i) == 0 )
		{
			divisorVec[divisor] = i;
			divisor++;
			temp++;
		}
	}

	if ( K <= temp )
	{
		std::cout << divisorVec[K - 1] << "\n";
	}
	else
	{
		std::cout << 0 << "\n";
	}
	return 0;
}