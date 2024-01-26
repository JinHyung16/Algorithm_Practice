#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 운동장 한 바퀴 - 수학 알고리즘
/// cout << fixed;를 통해 소수점을 고정한다.
/// cout.precision(n)을 통해 소수점 n자리까지 출력하도록 설정한다.
/// </summary>


const float pi = 3.141592;

int main(void)
{
	FastIO;

	int d1 = 0, d2 = 0; // 가로 길이 d1, 반지름 d2
	cin >> d1;
	cin >> d2;

	float result = (2 * d1) + (2 * pi * d2);

	cout << fixed;
	cout.precision(6); // 소수점 자리 출력 설정
	cout << result << "\n";
	return 0;
}