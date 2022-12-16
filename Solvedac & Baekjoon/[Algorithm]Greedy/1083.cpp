#include<iostream>
#include<vector>

/// <summary>
/// Gold4 - Greedy 알고리즘
/// 내림차순 정렬을 의미
/// i번째에 i+1부터 n까지 숫자중 최대 숫자가 오는데,
/// 그때 교환 횟수는 s이내에 가능하다면 교환을 한다
/// </summary>


using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n(0), s(0); //배열 크기 n과 교환 최대 횟수 s

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