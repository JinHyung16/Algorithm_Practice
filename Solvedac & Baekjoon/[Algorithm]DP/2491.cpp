#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver4 수열 - DP 알고리즘
/// dp의 핵심은 한번만 계산하자, 대신 꼭 전부 다 계산하자
/// 그리고 한번 할때 더 좋은게 있다면 그걸로 갱신해놓자!
/// vector초기화 시 n개보다 1개더 많이 초기화 하는건, 비교할 때 +1한 범위때문이다.
/// 즉 n번째 까지 비교할 땐 n+1과의 비교가 필요해서다.
/// 처음엔 이중 for문 돌렸는데, 생각해보니 그럴 필요가 없다
/// </summary>


int main(void)
{
	//입 출력 속도 up
	ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	vector<int> sequenceVec(n + 1, n + 1);
	int maxLength = 1;

	for (int i = 0; i < n; i++)
	{
		std::cin >> sequenceVec[i];
	}

	//최소 길이는 1(본인만 가능한 경우)
	int upCount = 1; //오름차순 일 때 측정
	int downCount = 1; //내림차순 일 때 측정

	for (int i = 0; i < n - 1; i++)
	{
		if (sequenceVec[i] <= sequenceVec[i + 1])
		{
			upCount++;
		}
		else
		{
			upCount = 1;
		}

		if (sequenceVec[i] >= sequenceVec[i + 1])
		{
			downCount++;
		}
		else
		{
			downCount = 1;
		}

		int maxCount = std::max(upCount, downCount);
		maxLength = std::max(maxLength, maxCount);
	}

	std::cout << maxLength << std::endl;

	return 0;
}