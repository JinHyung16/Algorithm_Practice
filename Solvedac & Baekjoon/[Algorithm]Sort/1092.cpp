#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Gold5 �� - sort �˰���
/// ���� ���԰� ū ũ���ο� ���� ���԰� ū �ڽ��� ��°� �ٽ�!
/// ��, ������ �ϰ��� ���� �ذ��� �������� ��찡 ������ ���
/// �ڽ��� ���������, �ش� �ڽ��� ����鼭 moveCount�� ������Ű��
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
		//���� ū ũ�����ε� �̰ͺ��� �� ū �ڽ��� ������ ���� �� ���� ����
		std::cout << -1 << std::endl;
		return 0;
	}

	int result = MoveTime(craneWeight, boxWeight);
	std::cout << result << std::endl;
	return 0;
}