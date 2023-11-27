#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 주식 - Greedy 알고리즘
/// 배열에 주가를 넣는다.
/// 맨 뒤에 주가부터 가져오는데
/// 최대 이익 < 현재 주가인 경우, 최대 이익 = 현재 주가로 교체한다.
/// 현재 주가 <= 최대 이익인 경우, 전체 이익 += (최대 이익 - 현재 주가)로 추가한다.
/// </summary>

int main(void)
{
	FastIO;

	int T = 0; // 테스트 케이스 개수 T
	cin >> T;
	int N = 0; // 날의 수 N
	vector<int> greedy;
	while (T--)
	{
		cin >> N;
		long long totalProfit = 0;

		greedy.resize(N, 0);
		for (int i = 0; i < N; i++)
		{
			cin >> greedy[i];
		}

		int maxProfit = greedy.back();
		for (int i = greedy.size() - 2; 0 <= i; i--)
		{
			if (maxProfit < greedy[i])
			{
				maxProfit = greedy[i];
			}
			else
			{
				totalProfit += (maxProfit - greedy[i]);
			}
		}

		cout << totalProfit << "\n";
		greedy.clear();
	}
	return 0;
}