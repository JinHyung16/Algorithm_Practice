#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 문자와 문자열 - 구현 알고리즘
/// 주어진 index를 이용할 때 -1해서 사용함을 잊지말자
/// </summary>

int main(void)
{
	FastIO;
	string input;
	int index = 0;
	cin >> input;
	cin >> index;

	cout << input[index - 1] << "\n";

	return 0;
}