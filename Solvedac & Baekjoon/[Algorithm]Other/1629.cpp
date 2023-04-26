#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���� - �������� �˰���
/// �ŵ������� ���õ� ������ A^B�� ���Ͽ� B�� ¦���� Ȧ���� ���� ������.
/// B�� ¦���� -> A^B = A^(B/2) * A^(B/2)
/// B�� Ȧ���� -> A^B = A^(B/2) * A^(B/2 + 1)�� ���� ��Ģ�� ���� A^(B/2) * A^(B/2) * A�� ���Ѵ�.
/// ������ ���⿡ % C�� �ؾ��ϹǷ�
/// ��ⷯ ���꿡 ����
/// B�� Ȧ���϶� (A^(B/2) * A^(B/2) * A) % C = ((A^(B/2) * A^(B/2)) % C ) * A % C��
/// </summary>

using namespace std;

long long C(0); //C�� ���� ������ ���

long long MyPow(long long A, long long B)
{
	if (B == 0) { return 1; }
	else if (B == 1) { return A % C; }

	long long temp = MyPow(A, B / 2); //A^(B/2)�� �ǹ�
	if (B % 2 == 0)
	{
		return (temp * temp) % C;
	}
	else
	{
		return ((temp * temp) % C) * A % C;
	}
	
}

int main(void)
{
	FastIO;

	long long A(0), B(0); //�ڿ��� A�� B�� ���Ѵ�

	std::cin >> A >> B >> C;
	long long remain = MyPow(A, B);
	std::cout << remain << "\n";
	return 0;
}