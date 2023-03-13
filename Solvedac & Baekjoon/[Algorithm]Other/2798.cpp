#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 ���� - ���Ʈ���� �˰���
/// ������ ī�� ���� ������ 3���� for���� ������ �Ѵ�.
/// �׷��� 3���� ī���� �տ� ���� ��� ����� ���� ���ʴ�� ���鼭 M�� ���� ����� ����� ã�´�.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	
	vector<int> cards(100, 0);
	int N(0), M(0); //ī���� ���� N, �̱�� �� M
	int result(0); //M�� �ִ��� ����� ���
	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		std::cin >> cards[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int sum = cards[i] + cards[j] + cards[k];
				if (sum <= M && result < sum)
				{
					result = sum;
				}
			}
		}
	}

	std::cout << result << "\n";
	return 0;
}