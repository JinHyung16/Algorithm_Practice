#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 홍익대학교 - 구현 알고리즘
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0; //특정 년도 N
	int open = 1946; // 개교 년도
	cin >> N;
	cout << (N - open) << "\n";
	return 0;
}