#include<iostream>

/// <summary>
/// Silver4 ���� ��� - Greedy �˰���
/// </summary>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //��� �ؾ��ϴ� ���� N ų�α׷�
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