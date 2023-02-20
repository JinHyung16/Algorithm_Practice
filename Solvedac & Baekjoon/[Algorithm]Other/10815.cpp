#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 숫자 카드 - 자료 구조 알고리즘
/// 이중 for문을 돌리면 O(n^2)으로 제한 시간안에 해결하기 어렵다.
/// binary_serach를 이용하는데 이미 제공하는 binary_search를 이용해도 되고,
/// 아니면 구현해도된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //가지고 있는 숫자 카드의 개수 N
	int M(0); //가지고 있는 숫자 카드인지 아닌지 구분해야 하는 개수 M
	std::cin >> N;
	vector<int> cards(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> cards[i];
	}

	std::cin >> M;
	vector<int> checkList(M);
	vector<int> checkResult(M, 0);
	for (int i = 0; i < M; i++)
	{
		std::cin >> checkList[i];
	}

	//오름차순 정렬
	std::sort(cards.begin(), cards.end());

	//binary search 관련 부분
	for (int i = 0; i < M; i++)
	{
		//std::binary_search(cards.begin(), cards.end(), M);
		int right = N - 1;
		int left = 0;
		while (left <= right)
		{
			int mid = (right + left) / 2;
			if (cards[mid] == checkList[i])
			{
				checkResult[i] = 1;
				break;
			}

			if (checkList[i] < cards[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		std::cout << checkResult[i] << " ";
	}
	std::cout << "\n";

	return 0;
}