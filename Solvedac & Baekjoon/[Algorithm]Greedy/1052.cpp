#include<iostream>

using namespace std;

/// <summary>
/// Silver1 물병 - Greedy 알고리즘
/// 물병을 1병부터 순서대로 증가시키면서 규칙을 찾아보자
/// 1병 -> {1} -> 1병 만듦
/// 2병 -> {1,1} -> {2} -> 1병 만듦
/// 3병 -> {1,1,1} -> {2,1} -> 2병 만듦
/// 4병 -> {1,1,1,1} -> {2,2} -> {4} -> 1병 만듦
/// 5병 -> {1,1,1,1,1} -> {2,2,1} -> {4,1} -> 2병 만듦
/// 6병 -> {1,1,1,1,1,1} -> {2,2,2} -> {4, 2} -> 2병 만듦
/// 7병 -> {1,1,1,1,1,1,1} -> {2,2,2,1} -> {4,2,1} -> 3병 만듦
/// 8병 -> {1,1,1,1,1,1,1,1} -> {2,2,2,2} -> {4,4} -> {8} -> 1병 만듦
/// 2의 제곱으로 이뤄진 병수는 모두 1병을 만듦
/// N이 7일때 /2한 값과 %2한 값을 통해 만들 수 있는 물병과 만들지 못한 1병이 있음을 알 수 있다
/// 즉 %2해서 남은면 그게 상점에서 구입한 한병이다.
/// 따라서 n을 계속 2로나누면서 %2 == 1이면 count 증가, count가 k와 같거나 작으면 종료
/// </summary>

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n = 0, k = 0;
	std::cin >> n >> k;

	if (n <= k)
	{
		std::cout << 0 << std::endl;
	}
	else
	{
		int bottleCount = 0;
		while (true)
		{
			int count = 0;
			int tempN = n;

			while (tempN > 0)
			{
				if (tempN % 2 == 1)
				{
					count++;
				}
				tempN /= 2;
			}

			if (count <= k)
			{
				break;
			}

			n++;
			bottleCount++;
		}
		std::cout << bottleCount << std::endl;
	}

	return 0;
}