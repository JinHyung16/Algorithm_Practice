#include<iostream>

/// <summary>
/// Silver5 수들의 합 - Greedy 알고리즘
/// 최댓값을 보고 type을 잘 지정하자
/// num의 경우 최소 1인 이유가 입력에 S의 최소가 1이기 때문
/// 주어진 S가 될때까지 num을 증가시키면서 더해 sum에 넣다가
/// sum이 S보다 커지면 그만큼 감소시켜 구해준다.
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long S(0); //자연수 S
	int N(0); //자연수 최댓값 N
	int num(1);
	long long sum(0);

	std::cin >> S;

	while (true)
	{
		sum += num;
		N++;
		if (sum > S)
		{
			N--;
			break;
		}
		num++;
	}

	std::cout << N << std::endl;
	return 0;
}