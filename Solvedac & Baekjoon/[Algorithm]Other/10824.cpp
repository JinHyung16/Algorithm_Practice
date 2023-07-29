#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 네 수 - 문자열 알고리즘
/// 만약 모든 수가 1000000이라면, ab를 합치면 10000001000000, cd를 합치면 10000001000000다.
/// 따라서 두 수의 합은 범위를 벗어나는 오류가 뜨기에, long long으로 바꾸기 위해 stoll(string)을 이용한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string a, b, c, d; //입력받을 A, B, C, D
	string left, right;
	std::cin >> a >> b >> c >> d;

	left = a + b;
	right = c + d;

	long long result = std::stoll(left) + std::stoll(right);
	
	std::cout << result << "\n";
	return 0;
}