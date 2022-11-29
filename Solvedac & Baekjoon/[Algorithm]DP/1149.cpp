#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver1 RGB 거리 - DP 알고리즘
/// 각 집 색은 RGB중 하나고, 이어진 순서끼린 같은색 X
/// 그렇다면 들어온 순서대로 R,G,B라고 생각하고
/// 첫번째부터 n번째 까지 고른 숫자의 합이 최소가 되면 되는데,
/// 만약 앞에서 R 골랐다면 다음은 R제외하고 골라야 하는 경우다.
/// </summary>

/// <summary>
/// #include<algorithm>에서 최대 2개까지 비교해 최솟값 반환하는 함수밖에 없어
/// 3개짜리는 이렇게 구현해야 한다.
/// </summary>
/// <param name="a"> 첫번째 인자 </param>
/// <param name="b"> 두번째 인자 </param>
/// <param name="c"> 세번째 인자 </param>
/// <returns> 3개의 인자중 가장 작은 intger 값을 리턴 </returns>
int minThree(int a, int b, int c)
{
	int minValue = std::min(a, b);
	return minValue < c ? minValue : c;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int houseCount = 0;
	int rgbCount = 3;

	std::cin >> houseCount;

	int cost = 0;
	vector<vector<int>> dp(houseCount + 1, vector<int>(rgbCount)); //r g b 3개니깐
	vector<vector<int>> houseCost(houseCount + 1, vector<int>(rgbCount));

	for (int i = 0; i < houseCount; i++)
	{
		for (int j = 0; j < rgbCount; j++)
		{
			//dp[i][0] = 빨간색 집, dp[i][1]은 초록색 집, dp[i][2]는 파란색 집으로 가정
			std::cin >> dp[i][j];
			//cost값을 메모이제이션하자
			houseCost[i][j] = dp[i][j];
		}
	}

	for (int i = 1; i < houseCount; i++)
	{
		//rgb 중 r선택했다 가정하면 이전 집은 g와 b중에서 get
		houseCost[i][0] = dp[i][0] + std::min(houseCost[i - 1][1], houseCost[i - 1][2]);

		//rgb 중 g선택했다 가정하면 이전집은 r과 b중에서 최소값 get
		houseCost[i][1] = dp[i][1] + std::min(houseCost[i - 1][0], houseCost[i - 1][2]);

		//rgb 중 b선택했다 가정하면 이전집은 r과 g중에서 get
		houseCost[i][2] = dp[i][2] + std::min(houseCost[i - 1][0], houseCost[i - 1][1]);
	}

	cost = minThree(houseCost[houseCount - 1][0], houseCost[houseCount - 1][1], houseCost[houseCount - 1][2]);

	std::cout << cost << std::endl;


	return 0;
}