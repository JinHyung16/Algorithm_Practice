#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 팩토리얼 0의 개수 - 수학 알고리즘
/// 
/// 1) 처음 시도 방법 -> 실패
/// recursion을 이용하면 시간초과와 메모리 측면에서 비효율이다.
/// 따라서 배열에 담아가면서 memoization을 이용해 recursion을 피한다.
/// 문제는 N이 500일때의 길이였다. 따라서 새로운 접근법을 생각해봤다.
/// 
/// 2) 소인수 분해 이용
/// 뒤의 0이 나오는 경우는 * 10한 경우밖에 없다.
/// 10은 소인수 분해하면 2*5다. 따라서 N!를 소인수 분해하여 2와 5의 나오는 개수를 찾고
/// 둘 중 최소값을 찾으면 된다.
/// </summary>

using namespace std;

long long Factorial(int n)
{
	long long twoCnt = 0;
	long long fiveCnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		while (temp % 2 == 0)
		{
			temp /= 2;
			twoCnt += 1;
		}

		while (temp % 5 == 0)
		{
			temp /= 5;
			fiveCnt += 1;
		}
	}

	return std::min(twoCnt, fiveCnt);
}
int main(void)
{
	FastIO;

	int N(0);
	std::cin >> N;

	long long zeroCnt = Factorial(N);

	std::cout << zeroCnt << "\n";
	return 0;
}