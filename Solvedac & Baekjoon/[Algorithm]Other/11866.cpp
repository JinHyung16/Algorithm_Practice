#include<iostream>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 요세푸스 문제 0 - 자료 구조 알고리즘
/// 원을 그려 제거하는건 마치 일렬로 놓았을 때,
/// i번째 제거한 카드를 맨 뒤로 보내서 제거하는거와 동일
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0), K(0); //N명의 사람, 순서대로 K번째 사람 제거
	queue<int> peopleQueue;

	std::cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		peopleQueue.push(i);
	}

	std::cout << "<";
	while (!peopleQueue.empty())
	{
		for (int i = 1; i < K; i++)
		{
			peopleQueue.push(peopleQueue.front());
			peopleQueue.pop();
		}

		std::cout << peopleQueue.front();
		if (peopleQueue.size() != 1)
		{
			std::cout << ", ";
		}
		peopleQueue.pop();
	}
	std::cout << ">";
	return 0;
}