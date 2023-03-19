#include<iostream>
#include<vector>
#include<deque>

/// <summary>
/// Silver3 회전하는 큐 - 자료구조 알고리즘
/// </summary>


using namespace std;

int main(void)
{
	deque<int> myDeque;

	int queSize = 0; //큐의 크기 N의 해당
	int outCount = 0; //뽑아내려는 수의 개수 M의 해당
	int outValue = 0; //뽑아 내려고 하는 수의 위치

	int curPoint = 0; // 현재 내가 위치해 있는 곳
	int minOutCount = 0; //뽑아 내려는 연산의 최소 값

	cin >> queSize >> outCount;

	//queue의 값 size만큼 해서 1씩 증가해 초기화 시키기
	for (int i = 0; i < queSize; i++)
	{
		myDeque.push_back(i+1); //값은 1부터 시작
	}

	for (int outIndex = 0; outIndex < outCount; outIndex++)
	{
		cin >> outValue;
		for (int dequeIndex = 0; dequeIndex < myDeque.size(); dequeIndex++)
		{
			if (myDeque[dequeIndex] == outValue)
			{
				curPoint = dequeIndex; //현재 위치 저장
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