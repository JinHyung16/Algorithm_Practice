#include<iostream>
#include<vector>

/// <summary>
/// Silver4 기타줄 - Greedy 알고리즘
/// 돈을 최소로 사용하기 위해선,
/// 지불해야할 돈과 현재 지불한 돈의 최소 값을 비교해보자
/// 패키지 살 때 생각해야할 상황이 두개다
/// 6개가 1 패키지니 (끊어진 기타줄 개수/6) 만큼 패키지로 구매하고, 남은 나머지가 있다면 (끊어진 기타줄 개수%6) 만큼은 낱개로 사는 경우와
/// 패키지로 구매하고, 남은 나머지가 있다면 차라리 패키지로 한번 더 구매하는 경우
/// 이렇게 두 상황에 있어 뭐가 더 최소인지 비교해줘야 한다.
/// </summary>

using namespace std;

const int MAXINT = 987654321;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N(0), M(0); //끊어진 기타줄 개수 N, 기타줄 브랜드 개수 M
	int packagePrices(0), singlePrices(0); //패키지 가격, 낱개 가격

	int min_sixPackage(MAXINT), min_single(MAXINT);
	std::cin >> N >> M;

	while (M--)
	{
		std::cin >> packagePrices >> singlePrices;
		min_sixPackage = std::min(min_sixPackage, packagePrices);
		min_single = std::min(min_single, singlePrices);
	}

	if (min_single * 6 <= min_sixPackage)
	{
		//낱개 6개 사는게 더 최소라면
		std::cout << min_single * N << std::endl;
	}
	else
	{
		//package로 (N/6)개 사는것과 나머지 필요한건 낱개로 구매한것을 합친것 과, 패키지를 추가로 구매한 것 중 최소를 찾는다
		int minPackage = std::min((N / 6) * min_sixPackage + (N % 6) * min_single, ((N / 6) + 1) * min_sixPackage);
		std::cout << minPackage << std::endl;
	}
	return 0;
}