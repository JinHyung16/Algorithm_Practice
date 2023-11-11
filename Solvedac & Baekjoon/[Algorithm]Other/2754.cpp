#include<iostream>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 학점계산 - 구현 알고리즘
/// double로 소수점 자리 조절을 원한다면
/// cout << fixed; cout.precision(출력 원하는 소수점 자리 수); 를 통해 맞춘다.
/// </summary>

int main(void)
{
	FastIO;

	string input;
	cin >> input;

	double answer = 0;

	switch (input[0])
	{
	case 'A':
		answer += 4.0;
		break;
	case 'B':
		answer += 3.0;
		break;
	case 'C':
		answer += 2.0;
		break;
	case 'D':
		answer += 1.0;
		break;
	case 'F':
		answer = 0.0;
		break;
	}

	switch (input[1])
	{
	case '+':
		answer += 0.3;
		break;
	case '-':
		answer -= 0.3;
		break;
	default:
		break;
	}

	cout << fixed;
	cout.precision(1);
	cout << answer;

	return 0;
}