#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 삼각형 외우기 - 기하학 알고리즘
/// 문제 조건에 맞춰 if문을 세운다.
/// 그 후 해당 조건에 맞는 값을 vector<string>에서 꺼내 읽는다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int angleA = 0, angleB = 0, angleC = 0; //세 각의 크기
	vector<string> triangle = { "Equilateral", "Isosceles", "Scalene", "Error" };
	std::cin >> angleA >> angleB >> angleC;
	if ( angleA == angleB && angleB == angleC )
	{
		std::cout << triangle[0] << "\n";
	}
	else if ( angleA + angleB + angleC == 180 && (angleA == angleB || angleB == angleC || angleA == angleC))
	{
		std::cout << triangle[1] << "\n";
	}
	else if ( angleA + angleB + angleC == 180 && angleA != angleB && angleB != angleC)
	{
		std::cout << triangle[2] << "\n";
	}
	else if ( angleA + angleB + angleC != 180 )
	{
		std::cout << triangle[3] << "\n";
	}

	return 0;
}