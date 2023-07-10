#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 세탁소 사장 동혁 - Greedy 알고리즘
/// 거스름돈을 입력받는다.
/// coins 벡터에는 가장 큰 동전의 액수부터 넣어둔다.
/// 그 후 C / coins[i]를 출력하고 C %= coins[i]를 통해 그 다음 동전에게 현재 i원을 다 거스르고 남은 액수를 넘겨준다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int T = 0, C = 0; //테스트 케이스 개수 T, 거스름돈 C
	vector<int> coins = { 25, 10, 5, 1 }; //quarter, dime, nickel, penny 순서로 액수를 *100 해서 환산함
	
	std::cin >> T;
	
	while ( T-- )
	{
		std::cin >> C;
		for ( int i = 0; i < coins.size(); i++ )
		{
			std::cout << C / coins[i] << " ";
			C %= coins[i];
		}
		std::cout << "\n";
	}
	return 0;
}