#include<iostream>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 �似Ǫ�� ���� 0 - �ڷ� ���� �˰���
/// ���� �׷� �����ϴ°� ��ġ �Ϸķ� ������ ��,
/// i��° ������ ī�带 �� �ڷ� ������ �����ϴ°ſ� ����
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0), K(0); //N���� ���, ������� K��° ��� ����
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