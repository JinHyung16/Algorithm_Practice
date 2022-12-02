#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Gold5 배 - sort 알고리즘
/// 가장 무게가 큰 크레인에 가장 무게가 큰 박스를 담는게 핵심!
/// 즉, 정렬을 하고나면 문제 해결이 쉬워지는 경우가 있으니 명심
/// 박스가 담겨졌으면, 해당 박스는 지우면서 moveCount를 증가시키자
/// </summary>

int MoveTime(const vector<int>& cWeight, const vector<int>& bWeight)
{
	vector<int> crans = cWeight;
	vector<int> boxes = bWeight;

	int moveCount = 0;

	while (!boxes.empty())
	{
		moveCount++;
		for (int i = 0; i < crans.size(); i++)
		{
			for (int j = 0; j < boxes.size(); j++)
			{
				if (crans[i] >= boxes[j])
				{
					boxes.erase(boxes.begin() + j);
					break;
				}
			}
		}
	}

	return moveCount;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int craneNum = 0;
	std::cin >> craneNum;

	vector<int> craneWeight(craneNum, 0);
	for (int i = 0; i < craneNum; i++)
	{
		std::cin >> craneWeight[i];
	}
	
	int boxNum = 0;
	std::cin >> boxNum;

	vector<int> boxWeight(boxNum, 0);
	for (int i = 0; i < boxNum; i++)
	{
		std::cin >> boxWeight[i];
	}

	std::sort(craneWeight.rbegin(), craneWeight.rend());
	std::sort(boxWeight.rbegin(), boxWeight.rend());

	if (craneWeight[0] < boxWeight[0])
	{
		//가장 큰 크레인인데 이것보다 더 큰 박스가 있으면 담을 수 없다 판정
		std::cout << -1 << std::endl;
		return 0;
	}

	int result = MoveTime(craneWeight, boxWeight);
	std::cout << result << std::endl;
	return 0;
}