#include<iostream>

using namespace std;

/// <summary>
/// Silver5 ��� ��� ���� - Greedy �˰���
/// �׸���� '�ּ���'�� Ű����, optimal�� �ظ� ������
/// �ٱ��� ũ�Ⱑ 2���� �����ġ�� ���� �ȿ� �ִ��� üũ�ϴ°� ����Ʈ
/// </summary>


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//n�� ��ü �ٴ� ĭ, m�� ���� �� ��ġ
	int n = 0, m = 0;

	int newM = 0;
	int appleCount = 0;
	int applePos = 0;
	int moveCount = 0;

	std::cin >> n >> m;
	if (m > 1)
	{
		newM = m - 1;
	}

	std::cin >> appleCount;

	for (int i = 0; i < appleCount; i++)
	{
		std::cin >> applePos;

		//applePos�� �ٱ��� ���� �� �ִ��� üũ�ؼ� ������ moveLength ���� ���ص� �ȴ�
		if (m - newM <= applePos && applePos <= m)
		{
			continue;
		} 
		else if (m < applePos)
		{
			moveCount += applePos - m;
			m += (applePos - m); //���� �� ��ġ�� ���� applePos�� �����ʿ� ������ ���������� �̵�
		}
		else if (applePos < m)
		{
			moveCount += m - applePos - newM; //�ٱ��� ���̸�ŭ length������ �ƴ϶� �ش� �ȿ� ������ ������ 1����
			m -= (m - applePos - newM); //���� �� ��ġ�� �������̰� applePos�� ���ʿ� ������ �������� �̵�
		}
	}

	std::cout << moveCount << "\n";
	return 0;
}