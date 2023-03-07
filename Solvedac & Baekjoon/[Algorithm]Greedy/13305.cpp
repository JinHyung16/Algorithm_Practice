#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 주유소 - Greedy 알고리즘
/// 현재 지점의 리터당 기름값과 다음 지점의 리터당 기름값을 비교해 더 작은걸 이용한다.
/// 다음 지점까지의 이동 비용 = (현재 이용중인 리터당 기름 값) * (다음 지점까지의 거리)가 된다.
/// 따라서 이 이동비용을 누적해가며 최소로 만든다.
/// </summary>

using namespace std;

vector<int> distanceCity(100000, 0);
vector<int> pricePerLitre(100000, 0);

int main(void)
{
	FastIO;

	int N(0); //도시의 개수 N
	long long minTotalCost(0);
	long long curCost(0);

	std::cin >> N;
	for (int i = 1; i < N; i++)
	{
		//1부터 시작하는 이유는 도시 사이의 거리는 다음 도시가 갖고 있어야 하기 때문이다.
		//즉 처음 도시의 거리는 항상 0이니깐
		std::cin >> distanceCity[i];
	}

	for (int i = 0; i < N; i++)
	{
		std::cin >> pricePerLitre[i];
	}

	curCost = pricePerLitre[0];	//현재의 기름값
	minTotalCost = curCost * distanceCity[1]; //두번째 지점까지 이동했을 때 비용

	for (int i = 1; i < N; i++)
	{
		if (curCost < pricePerLitre[i])
		{
			//curCost가 다음 지점의 비용보다 더 저렴하니 그냥 curCost로 간다.
			minTotalCost += (curCost * distanceCity[i + 1]);
		}
		else
		{
			//다음 지점의 비용이 더 저렴하다면, 해당 비용을 curCost로 바꾼다.
			curCost = pricePerLitre[i];
			minTotalCost += (curCost * distanceCity[i + 1]);
		}
	}

	std::cout << minTotalCost << "\n";
	return 0;
}