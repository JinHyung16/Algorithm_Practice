#include<iostream>
#include<vector>
#include<map>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 베스트셀러 - 자료 구조 알고리즘
/// map을 이용해 책 이름을 key로 받아, 해당 책이 들어와 map에 있다면 해당 value(int형)을 증가시킨다.
/// for(auto &a : map)을 통해 maxCnt를 찾고, 다시 for문을 돌려 maxCnt와 map.second가 같은면 출력하여 종료한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //하루동안 팔린 책의 개수 N
	int maxBookCnt = 0;
	std::cin >> N;

	map<string, int> books;
	for ( int i = 0; i < N; i++ )
	{
		string input;
		std::cin >> input;
		books[input]++;
	}

	for ( auto& book : books )
	{
		maxBookCnt = std::max(maxBookCnt, book.second);
	}

	for ( auto& book : books )
	{
		if ( maxBookCnt == book.second )
		{
			std::cout << book.first << "\n";
			return 0;
		}
	}
	return 0;
}