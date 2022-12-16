#include<iostream>
#include<vector>

/// <summary>
/// Gold4 - Greedy �˰���
/// �������� ������ �ǹ�
/// i��°�� i+1���� n���� ������ �ִ� ���ڰ� ���µ�,
/// �׶� ��ȯ Ƚ���� s�̳��� �����ϴٸ� ��ȯ�� �Ѵ�
/// </summary>


using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n(0), s(0); //�迭 ũ�� n�� ��ȯ �ִ� Ƚ�� s

	std::cin >> n;

	vector<int> greedy(n, 0);
	for (int i = 0; i < n; i++)
	{
		std::cin >> greedy[i];
	}

	std::cin >> s;
	
	for (int i = 0; i < n; i++)
	{
		int max = greedy[i];
		int maxIndex = i;

		for (int j = i + 1; j < n; j++)
		{
			if (s - (j - i) >= 0)
			{
				if (max < greedy[j])
				{
					max = greedy[j];
					maxIndex = j;
				}
			}
		}

		for (int j = maxIndex; i < j; j--)
		{
			std::swap(greedy[j], greedy[j - 1]);
		}
		s -= (maxIndex - i);
		if (s <= 0)
		{
			break;
		}
	}

	for (int i = 0; i < greedy.size(); i++)
	{
		std::cout << greedy[i] << " ";
	}
	
	return 0;
}