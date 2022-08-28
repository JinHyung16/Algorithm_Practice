#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int rd(0), w(0), h(0); // 실제 대각선, 넓이 비율, 높이 비율
	cin >> rd >> w >> h;

	// d : rd = w : rw
	// d : rd = h : rh
	// 비례식을 세우고 내항의 곱은 외항의 곱과 같다를 이용
	double d = sqrt(w * w + h * h); // 피타고라스의 정리 대각선 구하는 식
	double rw = (rd * w) / d; // 실제 넓이 구하는 식
	double rh = (rd * h) / d; // 실제 높이 구하는 식

	cout << (int)rw << " " << (int)rh;
	return 0;
}