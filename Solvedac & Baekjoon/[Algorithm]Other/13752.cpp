#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 히스토그램 - 구현 알고리즘
/// </summary>


int main(void)
{
	FastIO;

	int n = 0; // 테스트 케이스 개수
	cin >> n;
	while ( n-- )
	{
		int input = 0;
		cin >> input;
		for ( int i = 0; i < input; i++ )
		{
			cout << "=";
		}
		cout << "\n";
	}
	return 0;
}