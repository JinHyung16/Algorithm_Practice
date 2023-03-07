#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ������ - Greedy �˰���
/// ���� ������ ���ʹ� �⸧���� ���� ������ ���ʹ� �⸧���� ���� �� ������ �̿��Ѵ�.
/// ���� ���������� �̵� ��� = (���� �̿����� ���ʹ� �⸧ ��) * (���� ���������� �Ÿ�)�� �ȴ�.
/// ���� �� �̵������ �����ذ��� �ּҷ� �����.
/// </summary>

using namespace std;

vector<int> distanceCity(100000, 0);
vector<int> pricePerLitre(100000, 0);

int main(void)
{
	FastIO;

	int N(0); //������ ���� N
	long long minTotalCost(0);
	long long curCost(0);

	std::cin >> N;
	for (int i = 1; i < N; i++)
	{
		//1���� �����ϴ� ������ ���� ������ �Ÿ��� ���� ���ð� ���� �־�� �ϱ� �����̴�.
		//�� ó�� ������ �Ÿ��� �׻� 0�̴ϱ�
		std::cin >> distanceCity[i];
	}

	for (int i = 0; i < N; i++)
	{
		std::cin >> pricePerLitre[i];
	}

	curCost = pricePerLitre[0];	//������ �⸧��
	minTotalCost = curCost * distanceCity[1]; //�ι�° �������� �̵����� �� ���

	for (int i = 1; i < N; i++)
	{
		if (curCost < pricePerLitre[i])
		{
			//curCost�� ���� ������ ��뺸�� �� �����ϴ� �׳� curCost�� ����.
			minTotalCost += (curCost * distanceCity[i + 1]);
		}
		else
		{
			//���� ������ ����� �� �����ϴٸ�, �ش� ����� curCost�� �ٲ۴�.
			curCost = pricePerLitre[i];
			minTotalCost += (curCost * distanceCity[i + 1]);
		}
	}

	std::cout << minTotalCost << "\n";
	return 0;
}