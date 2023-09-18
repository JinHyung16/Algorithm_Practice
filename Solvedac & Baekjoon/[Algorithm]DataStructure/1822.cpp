#include<iostream>
#include<vector>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 차집합 - 자료 구조 알고리즘
/// set을 이용해 A를 입력받는다.
/// 그리고 B를 입력받을 때 A에 없다면 패스, 있으면 해당 원소 지운다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int nA = 0, nB = 0; //A집합 원소 개수, B집합 원소 개수
	std::cin >> nA >> nB;
	int input = 0;

	set<int> duplication;
	
	for ( int i = 0; i < nA; i++ )
	{
		std::cin >> input;
		duplication.insert(input);
	}

	for ( int i = 0; i < nB; i++ )
	{
		std::cin >> input;
		if ( duplication.find(input) == duplication.end() )
		{
			continue;
		}
		else
		{
			duplication.erase(input);
		}
	}

	std::cout << duplication.size() << "\n";

	for ( auto d : duplication )
	{
		std::cout << d << " ";
	}
	std::cout << "\n";

	return 0;
}