#include<iostream>

/// <summary>
/// Silver4 설탕 배달 - Greedy 알고리즘
/// </summary>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //배달 해야하는 설탕 N 킬로그램
	int fiveKG(0), threeKG(0);
	std::cin >> N;
	fiveKG = N / 5;

	while (true)
	{
		if (fiveKG < 0)
		{
			std::cout << -1 << std::endl;
			return 0;
		}

		if ((N - (fiveKG * 5)) % 3 == 0)
		{
			threeKG = (N - (fiveKG * 5)) / 3;
			break;
		}
		fiveKG--;
	}

	std::cout << fiveKG + threeKG << std::endl;
	return 0;
}