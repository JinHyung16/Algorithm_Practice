#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver1 ��� - Greedy �˰���
/// 3*3������ ���� ������ �������� �ƴ��� ����
/// �߰��� �Է��� ������� �ԷµǴµ�, cin�� ������ �ΰ� �Է¹ޱ⿡ scanf_s�� ����ؼ� �Է¹���
/// ���� vector�� �ƴ϶� �׳� int[][] �迭���¸� cin���� �Է� ����
/// �ƴϸ� char���·� �Է¹ް� - 48�ؼ� vector<int>�� ����
/// </summary>

vector<vector<int>> matrixA(51, vector<int>(50));
vector<vector<int>> matrixB(51, vector<int>(50));

void ReverseMatrix(int a, int b)
{
	for (int i = a - 1; i <= a + 1; i++)
	{
		for (int j = b - 1; j <= b + 1; j++)
		{
			matrixA[i][j] = 1 - matrixA[i][j];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int matrixCount(0), matrixSize(0);
	int reverseCount(0);
	char input;
	std::cin >> matrixCount >> matrixSize;
	
	for (int i = 0; i < matrixCount; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			std::cin >> input;
			matrixA[i][j] = input - 48;
		}
	}

	for (int i = 0; i < matrixCount; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			std::cin >> input;
			matrixB[i][j] = input - 48;
		}
	}

	for (int i = 0; i < matrixCount - 2; i++)
	{
		for (int j = 0; j < matrixSize - 2; j++)
		{
			if (matrixA[i][j] != matrixB[i][j])
			{
				reverseCount++;
				ReverseMatrix(i + 1, j + 1);
			}
		}
	}

	bool isReverse = false;
	for (int i = 0; i < matrixCount; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (matrixA[i][j] != matrixB[i][j])
			{
				isReverse = true;
			}
		}
	}
	
	if (isReverse)
	{
		std::cout << -1 << std::endl;
	}
	else
	{
		std::cout << reverseCount << std::endl;
	}
	return 0;
}