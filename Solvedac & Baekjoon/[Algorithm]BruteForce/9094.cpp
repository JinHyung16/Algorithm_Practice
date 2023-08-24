#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 수학적 호기심 - 브루트포스 알고리즘
/// 2중 for문을 돌면서 1부터 n까지 다 찾아본다.
/// 따라서 나머지가 없다면 정수라는 의미로 result값을 증가시킨다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int T = 0; //테스트 케이스의 개수 T
	std::cin >> T;
	int a = 0, b = 0;
	while ( T-- )
	{
		int n = 0, m = 0;	
		int result = 0;
		std::cin >> n >> m;
		for ( a = 1; a < n; a++ )
		{
			for ( b = a + 1; b < n; b++ )
			{
				if ( !((a * a + b * b + m) % (a * b)) )
				{
					result++;
				}
			}
		}
		std::cout << result << "\n";
	}
	return 0;
}