#include<iostream>
#include<vector>

/// <summary>
/// Silver4 ��Ÿ�� - Greedy �˰���
/// ���� �ּҷ� ����ϱ� ���ؼ�,
/// �����ؾ��� ���� ���� ������ ���� �ּ� ���� ���غ���
/// ��Ű�� �� �� �����ؾ��� ��Ȳ�� �ΰ���
/// 6���� 1 ��Ű���� (������ ��Ÿ�� ����/6) ��ŭ ��Ű���� �����ϰ�, ���� �������� �ִٸ� (������ ��Ÿ�� ����%6) ��ŭ�� ������ ��� ����
/// ��Ű���� �����ϰ�, ���� �������� �ִٸ� ���� ��Ű���� �ѹ� �� �����ϴ� ���
/// �̷��� �� ��Ȳ�� �־� ���� �� �ּ����� ������� �Ѵ�.
/// </summary>

using namespace std;

const int MAXINT = 987654321;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0), M(0); //������ ��Ÿ�� ���� N, ��Ÿ�� �귣�� ���� M
	int packagePrices(0), singlePrices(0); //��Ű�� ����, ���� ����

	int min_sixPackage(MAXINT), min_single(MAXINT);
	std::cin >> N >> M;

	while (M--)
	{
		std::cin >> packagePrices >> singlePrices;
		min_sixPackage = std::min(min_sixPackage, packagePrices);
		min_single = std::min(min_single, singlePrices);
	}

	if (min_single * 6 <= min_sixPackage)
	{
		//���� 6�� ��°� �� �ּҶ��
		std::cout << min_single * N << std::endl;
	}
	else
	{
		//package�� (N/6)�� ��°Ͱ� ������ �ʿ��Ѱ� ������ �����Ѱ��� ��ģ�� ��, ��Ű���� �߰��� ������ �� �� �ּҸ� ã�´�
		int minPackage = std::min((N / 6) * min_sixPackage + (N % 6) * min_single, ((N / 6) + 1) * min_sixPackage);
		std::cout << minPackage << std::endl;
	}
	return 0;
}