#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze5 카드 게임 - 수학 알고리즘
/// sum 변수에다가 입력받은 값을 더해간다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int input = 0;
	int sum = 0;

	for ( int i = 0; i < 5; i++ )
	{
		std::cin >> input;
		sum += input;	
	}

	std::cout << sum << "\n";
	return 0;
}