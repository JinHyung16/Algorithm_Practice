#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver3 게임 - Binary Search 알고리즘
/// 문제에서 게임 횟수가 최대 십억이라 십업으로 MAX_INT 설정
/// 바이너리 서치는 low+high에서 나눠서 확률이 달라지는 횟수를 구하는 것이다.
/// 즉 핵심은 배열의 정 중앙을 선택해 찾고자 하는 값과 비교하면서 찾는다.
/// </summary>

using namespace std;

const int MAX_INT = 1000000000;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long gameNum(0), winGame(0); //게임 횟수 X와 이긴게임 Y 의미
	std::cin >> gameNum >> winGame;

	int winPercent(0); //형택이의 승률 Z 의미
	winPercent = (winGame * 100) / gameNum;

	if (winPercent >= 99)
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	int low(0), high = MAX_INT;
	int winResult = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int binaryResult = (100 * (winGame + mid)) / (gameNum + mid);
		if (winPercent >= binaryResult)
		{
			winResult = mid + 1;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	std::cout << winResult << std::endl;
	return 0;
}