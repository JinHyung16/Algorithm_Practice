#include<iostream>
#include<string>

using namespace std;

/// <summary>
/// Silver1 팔 - Greedy 알고리즘
/// L과 R이 주어지는데, R은 L보다 크거나 같다! 즉 자리수도 고려하자
/// 또한 L과 R의 크기를 잘 보고 type을 잘 정하자
/// </summary>


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int eightMinCount = 0;
	string L, R;
	std::cin >> L >> R;

	if (L.size() != R.size())
	{
		std::cout << 0 << std::endl;
	}
	else
	{
		for (int i = 0; i < L.size(); i++)
		{
			if (L[i] != R[i])
			{
				break;
			}
			if (L[i] == R[i] && L[i] == '8')
			{
				eightMinCount++;
			}
		}
		std::cout << eightMinCount << std::endl;
	}

	return 0;
}