#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 슈퍼 마리오 - 누적합 알고리즘
/// 버섯의 값을 저장해둔다.
/// 그 후 sum에 result + 버섯의 i번째 값을 저장하고
/// sum이 100보다 크거나 같을 때 result와 sum이 만약 98과 102라면 102를 출력해야 하므로 이를 비교한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	vector<int> mushroom(10, 0);
	for ( int i = 0; i < 10; i++ )
	{
		std::cin >> mushroom[i];
	}

	int result = 0;
	for ( int i = 0; i < 10; i++ )
	{
		int  sum = result + mushroom[i];
		if ( 100 <= sum )
		{
			if ( sum - 100 <= 100 - result )
			{
				std::cout << sum << "\n";
			}
			else
			{
				std::cout << result << "\n";
			}
			return 0;
		}
		result = sum;
	}
	std::cout << result << "\n";
	return 0;
}