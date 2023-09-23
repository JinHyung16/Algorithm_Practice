#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 10부제 - 구현 알고리즘
/// vector의 차량 번호를 넣어두고,
/// day와 같을때마다 카운팅한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int day = 0; //날짜의 일의 자리 숫자
	int cnt = 0;
	vector<int> carNums(5, 0);

	std::cin >> day;
	for ( int i = 0; i < 5; i++ )
	{
		std::cin >> carNums[i];
		if ( day == carNums[i] )
		{
			cnt++;
		}
	}

	std::cout << cnt << "\n";
	return 0;
}