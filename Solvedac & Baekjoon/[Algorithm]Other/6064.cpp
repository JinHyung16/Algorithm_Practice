#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 카잉 달력 - 수학 알고리즘
/// <x:y>에서 각 x,y의 최대값은 M,N인것이다.
/// 문제에서 각 x,y가 주어진 최대값을 넘으면 1로 초기화고 아니면 +1씩 증가시킨다고 했다. 
/// 따라서 문제 예시를 보면 M=10, N=12면, 10번째 해는 <10,10>, 11번째 해는 <1, 11> 12번째 해는 <2,12> 13번째 해는 <3,1>이다.
/// 문제는 1씩 증가시켜가면서 풀다보면 O(MN)으로 시간초과가 난다.
/// 
/// 풀이)
/// 예를들어 M=5, N=6, x=3, y=4이면
/// 1. 우선 멸망년도를 생각한다. x가 M을 넘거나, y가 N이 된다면 멸망년도다.
/// 2. maxYear의 값을 구해 x가 이 값을 넘거나 (x-1) % N + 1 == y면 멸망년도로 멈춘다.
/// 3. maxYear < x면 -1을 아니면 x += M한값을 출력한다.
/// 
/// maxYear의 경우 M, N의 최소 공배수가 멸망년도이다.
/// </summary>

using namespace std;

int GCD(int a, int b)
{
	int temp(0);
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

int main(void)
{
	FastIO;

	int T(0); //test case
	int M(0), N(0), x(0), y(0); //주어진 M, N, x, y
	std::cin >> T;
	while (T--)
	{
		std::cin >> M >> N >> x >> y;
		int maxYear = LCM(M, N);
		while (true)
		{
			if (maxYear < x || (x - 1) % N + 1 == y)
			{
				break;
			}
			x += M;
		}

		if (maxYear < x)
		{
			std::cout << -1 << "\n";
		}
		else
		{
			std::cout << x << "\n";
		}
	}
	return 0;
}