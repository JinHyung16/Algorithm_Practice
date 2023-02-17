#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 �¶��� �Ǹ� - Greedy �˰���
/// ������������ �ް� ������ ū ������� �����Ѵ�.
/// i��°�� �ް� ������ ä�õƴٴ� �ǹ̴�, �ش� �ް��� 1������ i��°������ ����� �� �� �ִٴ� �Ҹ���.
/// �� i�� �ް��� ��� ��� ���� �ǹ��Ѵٰ� ��������
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0), M(0); //N���� �ް��� M���� �������� ��
	std::cin >> N >> M;

	vector<int> eggPrice(M, 0);
	int maxPrice(0), canBuyIndex(0);
	for (int i = 0; i < M; i++)
	{
		std::cin >> eggPrice[i];
	}

	std::sort(eggPrice.begin(), eggPrice.end(), std::greater<>());

	for (int i = 0; i < M; i++)
	{
		if (i < N)
		{
			int maxSalePrice = eggPrice[i] * (i + 1);
			if (maxPrice < maxSalePrice)
			{
				//i�� �� �� �ִ� ������� N���� Ŭ �� ����, �ֳĸ� �δ� 1���� �ް��� �� �� ������
				maxPrice = maxSalePrice;
				canBuyIndex = i;
			}
		}
		else
		{
			break;
		}
	}

	std::cout << eggPrice[canBuyIndex] << " " << maxPrice << "\n";
	return 0;
}