#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 로프 - Greedy 알고리즘
/// rope[i]는 i번째 rope가 견딜 수 있는 최대 중량을 의미하며
/// 각 로프가 들 수 있는 중량은 본인이 버틸 수 있는 최대 중량까지다.
/// 예제를 보면 10, 15일때 두 로프에 10씩 중량을 부과해야 첫 번째 루프도 만족하니
/// 최대 견딜 수 있는 무게는 10 + 10해서 20이다.
/// 즉, 내림차순한 뒤 rope[i] * i한 값 중 최대값을 찾으면 된다.
/// 주의) 내림차순으로 sort시 지금 vector사이즈를 미리 정하면 OutOfBounds가 뜬다.
/// 따라서 N을 입력받고 resize로 N만큼 size를 바꾸던가 아니면 N을 받은 후 vector를 만들자
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0);
	std::cin >> N;

	vector<long long> rope(N, 0);

	for (int i = 0; i < N; i++)
	{
		std::cin >> rope[i];
	}

	std::sort(rope.begin(), rope.begin() + N, std::greater<long long>());

	long long maxWeight = 0;
	for (int i = 0; i < N; i++)
	{
		//왜 i가 아닌 i+1이냐면 i는 0부터 시작인데 실제론 1번부터 시작해야하니
		long long temp = rope[i] * (i + 1);
		maxWeight = std::max(maxWeight, temp);
	}
	std::cout << maxWeight << "\n";
	
	return 0;
}