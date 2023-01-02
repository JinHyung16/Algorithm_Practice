#include<iostream>

/// <summary>
/// Bronze4 ���ڷ����� - Greedy �˰���
/// ������ �Ǿ��ִ� �ð��� �ʷ� �ٲ���
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int A(0), B(0), C(0); //�ð� ������ ��ư �� �ð� 5��, 1��, 10��
	int T(0); //�丮�ð� T��

	std::cin >> T;
	if (T % 10 != 0)
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	A = T / 300; //5���� 300��
	T %= 300;

	B = T / 60; //1���� 60��
	T %= 60;

	C = T / 10;

	std::cout << A << " " << B << " " << C << std::endl;
	return 0;
}