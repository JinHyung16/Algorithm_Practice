#include<iostream>

/// <summary>
/// Silver5 ������ �� - Greedy �˰���
/// �ִ��� ���� type�� �� ��������
/// num�� ��� �ּ� 1�� ������ �Է¿� S�� �ּҰ� 1�̱� ����
/// �־��� S�� �ɶ����� num�� ������Ű�鼭 ���� sum�� �ִٰ�
/// sum�� S���� Ŀ���� �׸�ŭ ���ҽ��� �����ش�.
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long S(0); //�ڿ��� S
	int N(0); //�ڿ��� �ִ� N
	int num(1);
	long long sum(0);

	std::cin >> S;

	while (true)
	{
		sum += num;
		N++;
		if (sum > S)
		{
			N--;
			break;
		}
		num++;
	}

	std::cout << N << std::endl;
	return 0;
}