#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 랜선 자르기 - 이분탐색 알고리즘
/// 필요한 랜선의 개수가 N
/// 따라서 각 입력받은 길이를 mid로 나눠 이 몫을 N과 비교
/// 몫이 N보다 크거나 같다면 start를 mid보다 한 칸 다음으로 옮겨 더 긴 길이로 N개를 만들 수 있는지 검사
/// 몫이 N보다 작다면 end를 mid보다 한 칸 전으로 옮겨, 더 짧은 길이를 이용하면 N개를 만들 수 있는지 검사한다.
/// 이때 문제의 N의 범위를 보면 int로 하면 오류나니 long long으로하자
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int K(0), N(0); //가지고 있는 랜선의 개수 K, 필요한 랜선의 개수 N
	std::cin >> K >> N;
	vector<long long> lanCable(K);
	long long maxLength(0);
	long long resultMax(0);

	for (int i = 0; i < K; i++)
	{
		std::cin >> lanCable[i];
		maxLength = std::max(maxLength, lanCable[i]);
	}

	long long start = 1, end = maxLength, mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int cur = 0;
		for (int i = 0; i < K; i++)
		{
			cur += (lanCable[i] / mid);
		}

		if (N <= cur)
		{
			start = mid + 1;
			resultMax = std::max(resultMax, mid);
		}
		else
		{
			end = mid - 1;
		}
	}

	std::cout << resultMax << "\n";
	return 0;
}