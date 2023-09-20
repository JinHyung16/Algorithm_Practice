#include<iostream>
#include<vector>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 임스와 함께하는 미니게임 - 자료구조 알고리즘
/// set을 통해 중복을 방지하며 player들을 입력 받는다.
/// 그리고 game의 종류에 따라 출력하는데 Y면 입력받은 인원을 다, F면 / 2, O면 / 3을 한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //신청 횟수 N
	char game; //같이 게임할 종류
	set<string> player;
	std::cin >> N >> game;
	for ( int i = 0; i < N; i++ )
	{
		string input;
		std::cin >> input;
		player.insert(input);
	}
	if ( game == 'Y' )
	{
		std::cout << player.size();
	}
	else if ( game == 'F' )
	{
		std::cout << player.size() / 2;
	}
	else if ( game == 'O' )
	{
		std::cout << player.size() / 3;
	}
	return 0;
}