#include<iostream>
#include<vector>
#include<queue>


using namespace std;

/// <summary>
/// Silver5 ī��1 - �ڷᱸ�� �˰���
/// vector�� �⺻! �ʿ信 ���� stack�� queue ������ �߿�
/// queue�� ���Լ���, pop�� �տ������� ����
/// �ݺ��� ���� ���� �� �����ϱ�!!
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