#include<iostream>
#include<vector>
#include<algorithm>

/// <summary>
/// Silver5 스네이크버드 - Greedy 알고리즘
/// Greedy를 해결할 때, 정렬 후 문제를 접근해보는 것도 좋다.
/// 먹을 수 있는 조건이 결국 작은것부터 차례대로 먹는걸 의미하기에 정렬을 해보자
/// </summary>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0); //과일의 개수 N
	int L(0); //스네이크버드 초기 길이
	std::cin >> N >> L;

	vector<int> fruitHeight(N, 0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> fruitHeight[i];
	}

	std::sort(fruitHeight.begin(), fruitHeight.end());
	for (int i = 0; i < N; i++)
	{
		if (fruitHeight[i] <= L)
		{
			//스네이크버드의 몸 길이보다 작거나 같은 높이의 과일이면 먹을 수 있다.
			L += 1;
		}
	}

	std::cout << L << std::endl;
	return 0;
}