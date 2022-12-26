#include<iostream>
#include<vector>
#include<queue>


using namespace std;

/// <summary>
/// Silver5 카드1 - 자료구조 알고리즘
/// vector는 기본! 필요에 따라 stack과 queue 선택이 중요
/// queue는 선입선출, pop시 앞에서부터 제거
/// 반복문 도는 기준 잘 생각하기!!
/// </summary>


int main(void)
{
	int cardCount = 0;
	std::cin >> cardCount;

	vector<int> dropDownCard;
	queue<int> cardQueue;

	for (int i = 1; i <= cardCount; i++)
	{
		cardQueue.push(i);
	}

	while(cardQueue.size() != 1)
	{
		dropDownCard.push_back(cardQueue.front());
		cardQueue.pop();
		cardQueue.push(cardQueue.front());
		cardQueue.pop();
	}

	for (int i = 0; i < dropDownCard.size(); i++)
	{
		std::cout << dropDownCard[i] << " ";
	}
	std::cout << cardQueue.front() << std::endl;

	return 0;
}