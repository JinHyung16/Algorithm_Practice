#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 블랙잭 - 브루트포스 알고리즘
/// 세장의 카드 합을 보려면 3개의 for문을 돌려야 한다.
/// 그렇게 3장의 카드의 합에 대해 모든 경우의 수를 차례대로 보면서 M과 가장 가까운 결과를 찾는다.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	
	vector<int> cards(100, 0);
	int N(0), M(0); //카드의 개수 N, 이기는 합 M
	int result(0); //M의 최대한 가까운 결과
	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		std::cin >> cards[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int sum = cards[i] + cards[j] + cards[k];
				if (sum <= M && result < sum)
				{
					result = sum;
				}
			}
		}
	}

	std::cout << result << "\n";
	return 0;
}