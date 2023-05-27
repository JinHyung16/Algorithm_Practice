#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ����Ʈ�� ���� - ���� �˰���
/// �����佺�׳׽��� ü�� ������ �� n������ �Ҽ��� ���� �� 2���� n�� �����ٱ��� ���鼭 ��� ������� �Ҽ����� ���ܽ�Ű�� ����̴�.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	vector<int> numVec(300000, 1); //��� ���� �Ҽ��� ����

	int n(1);
	while (n != 0)
	{
		std::cin >> n;
		int count(0);
		if (n == 0)
		{
			break;
		}

		//�����佺�׳׽��� ü ���� �� �׻� �迭 �ʱ�ȭ �ؼ� ��� ���� �Ҽ���� ����
		for (int i = 0; i <= 2 * n; i++)
		{
			numVec[i] = 1;
		}

		numVec[0] = 0; //0�� �Ҽ��� �ƴϴ�
		numVec[1] = 0; //1�� �Ҽ��� �ƴϴ�
		for (int i = 2; i <= 2 * n; i++)
		{
			if (numVec[i] == 1)
			{
				int temp = 2;
				while (i * temp <= 2 * n)
				{
					numVec[i * temp] = 0;
					temp++;
				}
			}
		}

		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (numVec[i] == 1)
			{
				count++;
			}
		}
		std::cout << count << "\n";
	}
	return 0;
}
