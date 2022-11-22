#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver5 - dp �˰���
/// A -> B / B -> BA�� ��ȯ
/// ex)k=3, A => B->BA->BAB, A : B = 1 : 2
/// ex)k=4, BAB->BABBA, A : B = 2 : 3
/// ex)k=5, BABBA->BABBABAB, A : B = 3 : 5
/// ��, k�� 2�̻��� �� ����, A�� ����=���� k���� B�� ���� / B�� ����=���� k���� A�� ���� + B�� ����
/// </summary>


int main(void)
{
	int k = 0; //��ư ������ Ƚ��
	cin >> k;
	
	vector<int> dpA(k + 1, 0);
	vector<int> dpB(k + 1, 0);

	dpA[0] = 1;
	dpA[1] = 0;
	dpB[0] = 0;
	dpB[1] = 1;

	for (int i = 2; i <= k; i++)
	{
		dpA[i] = dpB[i - 1];
		dpB[i] = dpA[i - 1] + dpB[i - 1];
	}

	std::cout << dpA[k] << " " << dpB[k] << std::endl;

	return 0;
}