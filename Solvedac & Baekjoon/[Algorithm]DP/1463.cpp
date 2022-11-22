#include<iostream>
#include<vector>

using namespace std;

/*
* Silver3 - 1�� �����
*/

int main(void)
{
	// �� �Է¿� ���� ������ �ּҸ� ã�°� Ű ����Ʈ, �Է��� x��� ����
	// ex)2 �Է½�, 1)2������ +1 -> ���� 2�� / 2)3���� ���� ������ -> ���� 1��
	// 2�� ���� ������ 0�� ��� f(x)= 1 + f(x/2)
	// 3���� ���� ������ 0�� ��� f(x) = 1 + f(x/3)
	// �� �� ��� ������ �߻��ϴ� ��� f(x) = f(x-1) + 1
	// �� x/2, x/3�̳ĸ� x�� input�ε� �̰� �� ���� �������ٴ°� ����� �ǹ��ϱ� �����̴�.
	
	// numVec�� ���� Ƚ�� �����س��� ��
	vector<int> numberVec(1000001, 0); //10^6 ������ ���� Ƚ�� �� 0���� �ʱ�ȭ

	int number = 0;

	numberVec[0] = 1; //�ֳĸ� 1�� �Ǳ����ؼ� +1 ���� �ѹ� ����
	numberVec[1] = 0; //�ֳĸ� 1�� ���� ���ص� �ٷ� 1�̴ϱ�

	cin >> number;

	for (int i = 2; i <= number; i++)
	{
		numberVec[i] = numberVec[i - 1] + 1;
		if (i % 2 == 0)
		{
			numberVec[i] = min(numberVec[i], numberVec[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			numberVec[i] = min(numberVec[i], numberVec[i / 3] + 1);
		}
	}

	cout << numberVec[number];

	return 0;
}