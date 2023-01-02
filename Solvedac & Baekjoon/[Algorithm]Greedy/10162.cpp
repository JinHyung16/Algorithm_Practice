#include<iostream>

/// <summary>
/// Bronze4 전자레인지 - Greedy 알고리즘
/// 분으로 되어있는 시간을 초로 바꾸자
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int A(0), B(0), C(0); //시간 조절용 버튼 각 시간 5분, 1분, 10초
	int T(0); //요리시간 T초

	std::cin >> T;
	if (T % 10 != 0)
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	A = T / 300; //5분은 300초
	T %= 300;

	B = T / 60; //1분은 60초
	T %= 60;

	C = T / 10;

	std::cout << A << " " << B << " " << C << std::endl;
	return 0;
}