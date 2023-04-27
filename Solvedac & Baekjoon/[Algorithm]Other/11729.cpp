#include<iostream>
#include<math.h>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 �ϳ��� ž �̵� ���� - ��� �˰���
/// �ϳ����� ž �Űܼ� �״� �ð��� ���� ���� N������ 2^N - 1�̴�.
/// 
/// ž �״� ���� (���� 1��°, ���� �� N��)
/// 1. N-1���� ������ 1�� ��뿡�� 3���� ���� 2�� ���� �ű��.
/// 2-1. 1�� ��뿡 �ִ� �� �Ʒ� ������ 3�� ���� �ű� ��,
/// 2-2. 2�� ��뿡 �ִ� N-1���� ������ 1�� ��븦 ���� 3�� ���� �Ű� �÷����´�.
/// 
/// pow �Լ��� #include<math.h>�� ������ �� ��������!
/// </summary>

using namespace std;

void Hanoi(int first, int second, int third, int cnt)
{
	if (cnt == 1)
	{
		std::cout << first << " " << third << "\n";
	}
	else
	{
		Hanoi(first, third, second, cnt - 1); //1�� ��뿡 �ִ°� 3���� ���� 2�� ���� �ű��
		std::cout << first << " " << third << "\n";
		Hanoi(second, first, third, cnt - 1); //���� ��뿡 �ִ� N-1���� ������ 1�� ��븦 ���� 3�� ���� �ű��
	}
}

int main(void)
{
	FastIO;

	int plateCount(0);
	std::cin >> plateCount;
	std::cout << (int)pow(2, plateCount) - 1 << "\n";
	Hanoi(1, 2, 3, plateCount);
	return 0;
}