#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 와글와글 숭고한 - 구현 알고리즘
/// </summary>


int main(void)
{
	FastIO;

	vector<pair<int, string>> univer(3);
	univer[0].second = "Soongsil";
	univer[1].second = "Korea";
	univer[2].second = "Hanyang";

	cin >> univer[0].first >> univer[1].first >> univer[2].first;
	
	int sum = 0;
	for ( int i = 0; i < 3; i++ )
	{
		sum += univer[i].first;
	}

	if ( 100 <= sum )
		cout << "OK" << "\n";
	else
	{
		sort(univer.begin(), univer.end());
		cout << univer[0].second << "\n";
	}
	return 0;
}