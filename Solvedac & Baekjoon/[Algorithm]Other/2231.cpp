#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 분해합 - 브루트포스 알고리즘
/// 주어진 분해합 N에 대해 M을 찾으려면 다음과 같이 진행한다.
/// 1) 1부터 N까지의 분해합을 다 구해서 sum에다가 저장하고 있는다.
/// 2) sum == N이 된 순간, i의 값이 생성자이므로 해당 i를 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //분해합 N
	std::cin >> N;

	int sum(0);
	int constructorNum(0);

	for (int i = 1; i <= N; i++)
	{
		sum = i;
		int temp = i;
		while (temp > 0)
		{
			sum += (temp % 10);
			temp /= 10;
		}

		if (sum == N)
		{
			constructorNum = i;
			break;
		}
	}

	std::cout << constructorNum << "\n";
	return 0;
}