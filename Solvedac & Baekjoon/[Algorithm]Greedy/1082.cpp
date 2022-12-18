#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

/// <summary>
/// Gold3 방 번호 - Greedy 알고리즘
/// 동전 거슬러 주는 문제와 비슷해 보인다.
/// pair를 이용해 방번호와 가격을 저장해두자
/// pair sort시 기준이 방 가격 즉 second값으로 따로 Compair함수 구현해주자
/// 구현하기 귀찮으면 (방번호, 방가격) -> (방가격, 방번호) 순서로 바꾸기
/// Room[0]의 방 번호가 0이면 전체 숫자가 0이 안되도록
/// Room[1]의 방 번호가 되도록 해줘야 한다.
/// 초기 vector로 구입한 방 저장해뒀는데, 마지막 출력시 시간을 더 잡아먹어 변경이 필요했다.
/// </summary>


using namespace std;

bool Compair(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
	{
		return a.second < b.second; //second값이 더 작은게 앞으로 오게
	}
	else if (a.first < b.first)
	{
		return a.second < b.second;
	}
	else if (a.first > b.first)
	{
		return a.second > b.second;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n(0), m(0); //문방구에서 파는 숫자 최대 범위 n-1, 준비한 금액
	vector<int> Price(10, 0); //방 개수별 가격들 저장
	vector<pair<int, int>> Room; //방 호와 가격

	std::cin >> n;
	for (int i = 0; i < n; i++) 
	{ 
		std::cin >> Price[i];
		Room.push_back(make_pair(Price[i], i)); //방번호, 방 가격 순서대로 저장
	}
	std::cin >> m;

	std::sort(Room.begin(), Room.end()); //pair의 first기준으로 오름차순 정렬, first같으면 second를 오름차순 정렬함
	//std::sort(Room.begin(), Room.end(), Compair);

	if (n == 1)
	{
		std::cout << 0 << std::endl;
		return 0;
	}

	string purchaseMax;
	if (Room[0].second != 0)
	{
		//가장 싼 가겨이라면 많이 사둬야 한다
		int cnt = m / Room[0].first;
		for (int i = 0; i < cnt; i++)
		{
			purchaseMax += to_string(Room[0].second);
		}
		m -= (cnt * Room[0].first);
	}
	else
	{
		int temp = m - Room[1].first;
		if (temp < 0)
		{
			std::cout << 0 << std::endl;
			return 0;
		}
		purchaseMax += to_string(Room[1].second);
		int cnt = temp / Room[0].first;
		for (int i = 0; i < cnt; i++)
		{
			purchaseMax += to_string(Room[0].second);
		}
		m = temp - (cnt * Room[0].first);
	}

	for (int i = 0; i < purchaseMax.size(); i++)
	{
		bool IsPriced = false;
		int cur = Price[purchaseMax[i] - '0'];
		for (int j = n - 1; j >= 0; j--)
		{
			if (m - (Price[j] - cur) >= 0)
			{
				m -= (Price[j] - cur);
				IsPriced = true;
				purchaseMax[i] = j + '0';
			}

			if (IsPriced)
			{
				break;
			}
		}

		if (!IsPriced)
		{
			break;
		}
	}

	std::cout << purchaseMax.c_str() << std::endl;
	return 0;
}