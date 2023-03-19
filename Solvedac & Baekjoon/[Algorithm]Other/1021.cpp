#include<iostream>
#include<vector>
#include<deque>

/// <summary>
/// Silver3 ȸ���ϴ� ť - �ڷᱸ�� �˰���
/// </summary>


using namespace std;

int main(void)
{
	deque<int> myDeque;

	int queSize = 0; //ť�� ũ�� N�� �ش�
	int outCount = 0; //�̾Ƴ����� ���� ���� M�� �ش�
	int outValue = 0; //�̾� ������ �ϴ� ���� ��ġ

	int curPoint = 0; // ���� ���� ��ġ�� �ִ� ��
	int minOutCount = 0; //�̾� ������ ������ �ּ� ��

	cin >> queSize >> outCount;

	//queue�� �� size��ŭ �ؼ� 1�� ������ �ʱ�ȭ ��Ű��
	for (int i = 0; i < queSize; i++)
	{
		myDeque.push_back(i+1); //���� 1���� ����
	}

	for (int outIndex = 0; outIndex < outCount; outIndex++)
	{
		cin >> outValue;
		for (int dequeIndex = 0; dequeIndex < myDeque.size(); dequeIndex++)
		{
			if (myDeque[dequeIndex] == outValue)
			{
				curPoint = dequeIndex; //���� ��ġ ����
				break;
			}
		}

		if (curPoint < myDeque.size() - curPoint)
		{
			for (int i = 0; i < myDeque.size(); i++)
			{
				if (myDeque.front() == outValue)
				{
					myDeque.pop_front();
					break;
				}
				minOutCount++;
				myDeque.push_back(myDeque.front());
				myDeque.pop_front();
			}
		}
		else
		{
			for (int i = 0; i < myDeque.size(); i++)
			{
				if (myDeque.front() == outValue)
				{
					myDeque.pop_front();
					break;
				}
				minOutCount++;
				myDeque.push_front(myDeque.back());
				myDeque.pop_back();
			}
		}
	}

	cout << minOutCount << endl;
	return 0;
}