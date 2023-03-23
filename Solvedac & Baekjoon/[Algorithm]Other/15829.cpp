#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 Hashing - ���ڿ�,�ؽ� �˰���
/// �ҹ��� ���ĺ� ������ 97�̴�. ���� �ش� ���ĺ� - 96�ϸ� ������ �ȴ�.
/// �������� ������ �־��� ���� ��ȯ�ϸ� �ȴ�.
/// 
/// mod ������ �Ӽ��� ������ ����. (a+b) mod m = {(a mod m)+(b mod m)} mod m�̴�
/// �̶� +�� �ƴ� -�� *�� ���ؼ��� �����ϴ�.
/// 
/// �ش� ������ (ai * r^i) mod M�̹Ƿ� �̴� {(ai mod M) * (b mod M)} mod M���� ���� ����.
/// 1)a*r mod M�� ���� �� �������
/// 2)pow(r,n)�� ����Ѵ�.
/// �̶� �ش� �ĵ��� mod�� �Ӽ��� ���� �����ϱ�
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int L(0); //���ڿ��� ����
	int R(31); // ������ �־��� �Ҽ� 31
	long long M(1234567891); //������ �־��� ���μ� M
	string input;

	std::cin >> L;
	std::cin >> input;

	long long hash(0);
	long long r(1); //�������� R�� �� �� �̷��� �ö󰡴µ� �װ� �ǹ�
	int a(0);
	for (int i = 0; i < L; i++)
	{
		a = (input[i] - 96);
		hash = (hash + (a * r)) % M; // �ռ� ���� H�� + (a mod M * (b mod M)) mod M
		r = (r * R) % M; //r mod M
	}

	std::cout << hash << "\n";

	return 0;
}