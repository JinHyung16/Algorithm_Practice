#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 팰린드롬 척화비 - 애드 혹 알고리즘
/// 수미상관이면서 팰린드롬이려면, 모든 문자가 다 하나로 같은 문자열은 이를 만족한다.
/// 문제에서 그 중 하나만 출력하라 했으므로 그냥 아무 문자나 다 같게하여 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	int N = 0; //길이 N인 수미상관 이면서 팰린드롬인 문자열
	std::cin >> N;

	for ( int i = 0; i < N; i++ )
	{
		std::cout << "b";
	}
	std::cout << "\n";
	return 0;
}