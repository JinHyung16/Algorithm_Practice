#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver5 올림픽 - 정렬 알고리즘
/// 입력 변수가 4개로 하나의 id를 통해 관리해야 하기에
/// 구조체를 만들어 진행했다.
/// </summary>

struct Country
{
	int id;
	int gold;
	int silver;
	int bronze;
};

bool CompareSort(Country a, Country b)
{
	if (b.gold < a.gold)
		return true;
	else if (b.gold == a.gold)
	{
		if (b.silver < a.silver)
			return true;
		if (b.silver == a.silver)
			if (b.bronze < a.bronze) 
				return true;
	}
	return false;
}
int main(void)
{
	FastIO;
	int N = 0, K = 0; // 국가의 수 N, 등수를 알고 싶은 국가 K
	cin >> N >> K;

	vector<Country> country(N);

	for (int i = 0; i < N; i++)
	{
		int id = 0, g = 0, s = 0, b = 0;
		cin >> id >> g >> s >> b;
		country[i].id = id;
		country[i].gold = g;
		country[i].silver = s;
		country[i].bronze = b;
	}
	
	sort(country.begin(), country.end(), CompareSort);

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		if (country[i].id == K)
		{
			result = i;
			break;
		}
	}

	// 선택된 국가와 금,은,동이 같은지 확인한다.
	int sameCountry = 0;
	for (int i = result - 1; 0 <= i; i--)
	{
		if (country[i].gold != country[result].gold || country[i].silver != country[result].silver 
			|| country[i].bronze != country[result].bronze) 
		{
			break;
		}
		sameCountry++;
	}
	cout << result - sameCountry + 1 << "\n";
	return 0;
}