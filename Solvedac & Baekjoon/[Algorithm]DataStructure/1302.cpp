#include<iostream>
#include<vector>
#include<map>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ����Ʈ���� - �ڷ� ���� �˰���
/// map�� �̿��� å �̸��� key�� �޾�, �ش� å�� ���� map�� �ִٸ� �ش� value(int��)�� ������Ų��.
/// for(auto &a : map)�� ���� maxCnt�� ã��, �ٽ� for���� ���� maxCnt�� map.second�� ������ ����Ͽ� �����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //�Ϸ絿�� �ȸ� å�� ���� N
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