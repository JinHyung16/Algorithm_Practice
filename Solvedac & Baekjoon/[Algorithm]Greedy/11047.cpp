#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ���� 0- Greedy �˰���
/// ������ ���� �����ַ��� �켱 ū �ݾ׺��� �Ž����ش�.
/// �� �� �׸����ϰ� �ذ�
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0), K(0); //������ ���� N, ��ġ�� �� K
	std::cin >> N >> K;
	vector<int> coinPrice(N, 0);
	int minExchangeCnt(0);

	for (int i = 0; i < N; i++)
	{
		std::cin >> coinPrice[i];
	}

	//���� ū ������ ���� �ټ��� ������ ������ ��������.
	std::sort(coinPrice.begin(), coinPrice.end(), std::greater<>());
	for (int i = 0; i < coinPrice.size(); i++)
	{
		while (true)
		{
			if (K - coinPrice[i] < 0)
			{
				break;
			}
			minExchangeCnt++;
			K -= coinPrice[i];
		}
	}

	std::cout << minExchangeCnt << "\n";
	return 0;
}