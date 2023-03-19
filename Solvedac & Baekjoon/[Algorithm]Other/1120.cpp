#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

/// <summary>
/// Silver4 ���ڿ� - ���Ʈ���� �˰���
/// </summary>

int MIN_DIFFERENCE = 50; //�ֳĸ� ���ڿ� �ִ� ���̰� 50�̹Ƿ� ���� �� ���ڿ��� �� �ٸ��� �ּ� 50�� �ʿ�

int main(void)
{
	string firstString;
	string secondString;

	int lengthDifference = 0;
	int maxMinDifference = MIN_DIFFERENCE;

	cin >> firstString >> secondString;

	lengthDifference = (int)(secondString.length() - firstString.length()); //�� ���ڿ��� ���� ����

	//����ϰ� ����� ���� �ּ��� �� -> ��ŭ ��ġ�ϳ� == ���� ���̰� �ּ��� ���� ����

	for (int i = 0; i <= lengthDifference; i++)
	{
		int curDifference = 0;

		for (int j = 0; j < firstString.length(); j++)
		{
			//���� �ٸ� ������ Ȯ��
			if (firstString[j] != secondString[i + j])
			{
				curDifference++;
			}
		}

		//�ּ����� �ٸ� ������ max�� �Ϳ� ��� �κ��� �ּҷ� �ٸ��� ����
		maxMinDifference = min(maxMinDifference, curDifference);
	}

	cout << maxMinDifference;

	return 0;
}