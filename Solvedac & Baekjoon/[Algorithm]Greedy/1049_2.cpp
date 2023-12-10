#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver4 기타줄 - Greedy 알고리즘
/// 패키지로만 구매, 낱개로만 구매, 패키지+낱개 로만 구매
/// 3가지 경우 중 가장 적은 금액을 내는 경우를 채택한다.
/// 1) 패키지로만 구매 -> (N / 6 + 1) * minSet
/// 2) 낱개로만 구매 -> N * minSingle
/// 3) 낱개 + 패키지 구매 -> (N / 6 * minSet) + N % 6 * minSingle
/// </summary>

int main(void)
{
	FastIO;

	int N = 0, M = 0; // 끊어진 기타줄 N개 기타줄 브랜드 M개
	cin >> N >> M;

	int packagePrice = 0, singlePrice = 0; // 패키지 가격, 낱개 가격
	int minSet = 987654321, minSingle = 987654321;
	for (int i = 0; i < M; i++)
	{
		cin >> packagePrice >> singlePrice;
		minSet = min(packagePrice, minSet);
		minSingle = min(singlePrice, minSingle);
	}

	int result = min((N / 6 + 1) * minSet, min(N / 6 * minSet + N % 6 * minSingle, N * minSingle));
	cout << result << "\n";
	return 0;
}