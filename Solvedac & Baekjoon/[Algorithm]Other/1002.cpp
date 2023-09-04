#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 터렛 - 수학 알고리즘
/// 교점이 생기려면 다음과 같은 3가지 경우다.
/// 1. 두 원이 외접한다.
/// 2. 두 원이 서로 다른 두 점에서 만난다.
/// 3. 두 점이 내접한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int T = 0; //테스트 케이스의 개수 T
	std::cin >> T;
	while ( T-- )
	{
		int x1 = 0, y1 = 0, r1 = 0, x2 = 0, y2 = 0, r2 = 0;
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		double d = std::sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
		double sub = 0;
		if ( r2 < r1 )
		{
			sub = r1 - r2;
		}
		else
		{
			sub = r2 - r1;
		}

		if ( d == 0 && r1 == r2 )
		{
			std::cout << "-1" << "\n";
		}
		else if ( r1 + r2 == d || sub == d )
		{
			std::cout << "1" << "\n";
		}
		else if ( sub < d && d < (r1 + r2) )
		{
			std::cout << "2" << "\n";
		}
		else
		{
			std::cout << "0" << "\n";
		}
	}
	return 0;
}