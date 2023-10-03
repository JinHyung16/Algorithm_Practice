#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 나머지 - 수학 알고리즘
/// 문제에 주어진 조건대로 출력한다.
/// </summary>

int main(void)
{
	FastIO;
	
	int A = 0, B = 0, C = 0; //입력받을 세 수 A, B, C
	std::cin >> A >> B >> C;
	
	std::cout << (A + B) % C << "\n";
	std::cout << ((A % C) + (B % C)) % C << "\n";
	std::cout << (A * B) % C << "\n";
	std::cout << ((A % C) * (B % C)) % C << "\n";

	return 0;
}