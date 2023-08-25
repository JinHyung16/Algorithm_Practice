#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 순서쌍의 곱의 합 - 누적 알고리즘
/// 문제 예시 2,3,4를 기준으로 보면
/// result = (2*3) + (2*4) + (3*4)다
/// 문제는 이렇게 풀면 시간 제한이 걸리니 방법을 바꾼다.
/// sum = 2+3+4를 한다.
/// 그 후 result에는 2*(9-2) + 3 *(9-3) + 4* (9-4)를 진행한다.
/// 이 의미는 모든 숫자가 다른 숫자들과 다 연산된 것이다. 이때 중복되는게 있으니 result / 2를 진행한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //입력 받을 정수의 개수 N
	std::cin >> N;
	vector<long long> prefix(N, 0);
	long long sum = 0, result = 0;
	for ( int i = 0; i < N; i++ )
	{
		std::cin >> prefix[i];
		sum += prefix[i];
	}

	for ( int i = 0; i < N; i++ )
	{
		result += prefix[i] * (sum - prefix[i]);
	}
	std::cout << result / 2 << "\n";
	return 0;
}