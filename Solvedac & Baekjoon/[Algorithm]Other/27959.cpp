#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 초코바 - 구현 알고리즘
/// </summary>


int main(void)
{
	FastIO;

	int N = 0, M = 0; // 백원 동전 N개 M원인 초코바
	cin >> N >> M;
	
	if ( M <= 100 * N )
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";

	return 0;
}