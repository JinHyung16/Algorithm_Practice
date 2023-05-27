#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 베르트랑 공준 - 수학 알고리즘
/// 에라토스테네스의 체는 임의의 수 n까지의 소수를 구할 때 2부터 n의 제곱근까지 돌면서 모든 배수들을 소수에서 제외시키는 방식이다.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	vector<int> numVec(300000, 1); //모든 수는 소수라 가정

	int n(1);
	while (n != 0)
	{
		std::cin >> n;
		int count(0);
		if (n == 0)
		{
			break;
		}

		//에라토스테네스의 체 시작 전 항상 배열 초기화 해서 모든 수는 소수라고 가정
		for (int i = 0; i <= 2 * n; i++)
		{
			numVec[i] = 1;
		}

		numVec[0] = 0; //0은 소수가 아니다
		numVec[1] = 0; //1도 소수가 아니다
		for (int i = 2; i <= 2 * n; i++)
		{
			if (numVec[i] == 1)
			{
				int temp = 2;
				while (i * temp <= 2 * n)
				{
					numVec[i * temp] = 0;
					temp++;
				}
			}
		}

		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (numVec[i] == 1)
			{
				count++;
			}
		}
		std::cout << count << "\n";
	}
	return 0;
}
