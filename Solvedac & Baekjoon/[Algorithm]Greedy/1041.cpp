#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Gold5 �ֻ��� - Greedy �˰���
/// N¥�� �ֻ��� �ֿ����� ����°� N^3�� ¥�� ����
/// ���ֺ��� �� ���� ���̴� �鿡 �ּڰ��� ���� �ȴ�
/// �׸��� �����ϸ� A-F / E-B / D-C�� ���ֺ��� ��
/// N���� 2�̻���� 3���� ���̴� ���� �ּڰ� = (3���� ������) * 4, 
/// 2���� ���̴� ���� �ּڰ� = (2���� ������) * 4*(N-1) + 4*(N-2),
/// 1���� ���̴� ���� �ּڰ� = (1��� ������) * 4*((N-1)*(N-2)) + (N-2)*(N-2)
/// </summary>

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long n = 0;
	std::cin >> n;

	vector<int> dice(6, 0); //�⺻������ �ֻ����� 6�麸�� 1���� ���� ����� �׷��� vector�� i+1���� ���� �ȳ�
	long long allSum = 0;
	int maxNum = 0;

	for (int i = 0; i < 6; i++)
	{
		std::cin >> dice[i]; //������� A,B,C,D,E,F -> index ��ȣ�� 0,1,2,3,4,5 ��� ����
		allSum += dice[i];
		maxNum = std::max(maxNum, dice[i]);
	}

	if (n == 1)
	{
		//1�϶�, �� ���ϰ� ���� ū ���� �Ѱ��� ���ָ� �ȴ�
		std::cout << allSum - maxNum;
		return 0;
	}
	allSum = 0;
	maxNum = 0;

	dice[0] = std::min(dice[0], dice[5]);
	dice[1] = std::min(dice[1], dice[4]);
	dice[2] = std::min(dice[2], dice[3]);

	//dice�� 0~2��° index���� �� 3���� �ּҰ��ְ� ���� �Ǵϱ� sort���ش�
	//���� ���� �� ���� 3��, 2��, 1�鿡 ������ ��ġ
	//�׷��� 3���� �� + 2���� �� + 1���� ���� ���� �ּڰ��� �Ǳ� ����
	std::sort(dice.begin(), dice.begin() + 3);
	int view1 = dice[0];
	int view2 = view1 + dice[1];
	int view3 = view2 + dice[2];

	allSum += view3 * 4;
	allSum += view2 * (4 * (n - 2) + 4 * (n - 1));
	allSum += view1 * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2));
	std::cout << allSum << std::endl;
	return 0;
}