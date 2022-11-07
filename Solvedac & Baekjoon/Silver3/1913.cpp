#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	//�����̴� ������ (�� ������ �Ʒ� ����) �ݺ�
	int dir = 0; //col, row�� +1 �����ؼ� ���� ������ ����
	int vecNum = 1;
	int pivot = 1;

	int vecSize = 0;
	int findNum = 0;
	cin >> vecSize;
	cin >> findNum;
	vector<vector<int>> snailVec((vecSize + 1), vector<int>((vecSize + 1), 0));

	int row = vecSize / 2, col = vecSize / 2; //�߾� �ǹ�
	snailVec[row][col] = 1;

	while(vecNum < (vecSize * vecSize))
	{
		if (dir == 0) // ���� �̵�
		{
			for (int j = 0; j < pivot; j++)
			{
				snailVec[row--][col] = vecNum++;
			}
			if (vecNum == vecSize * vecSize) 
			{ 
				break; 
			}
		}
		else if (dir == 1) // �� �̵�
		{
			for (int j = 0; j < pivot; j++)
			{
				snailVec[row][col++] = vecNum++;
			}
			pivot++;
		}
		else if (dir == 2) // �Ʒ� �̵�
		{
			for (int j = 0; j < pivot; j++)
			{
				snailVec[row++][col] = vecNum++;
			}
		}
		else if (dir == 3) // ������ �̵�
		{
			for (int j = 0; j < pivot; j++)
			{
				snailVec[row][col--] = vecNum++;
			}
			pivot++;
		}

		dir = (dir + 1) % 4;
	}
	
	
	for (int i = 0; i < vecSize; i++)
	{
		for (int j = 0; j < vecSize; j++)
		{
			std::cout << snailVec[i][j] << " ";
		}
		std::cout << std::endl;
	}
	

	for (int i = 0; i < vecSize; i++)
	{
		for (int j = 0; j < vecSize; j++)
		{
			if (snailVec[i][j] == findNum)
			{
				std::cout << i + 1 << " " << j + 1 << std::endl;
				break;
			}
		}
	}

	snailVec.clear();
	return 0;
}