#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 직각삼각형 - 수학 알고리즘
/// 삼각형이되려면 (가로 제곱) + (세로 제곱) = (빗변 제곱)이면 삼각형이다.
/// 문제를 보면 입력 순서가 정해지지 않았다. 이에 길이를 비교해 가장 긴 길이를 빗변으로 놔야한다.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	string triangle = "right";
	string nonTriangle = "wrong";
	int w(0), l(0), h(0); //가로 세로 높이 순서대로 입력받는다.
	while (true)
	{
		int temp = 0;
		std::cin >> w >> l >> h;
		if (w == 0 && l == 0 && h == 0)
		{
			break;
		}

		if (w > l)
		{
			temp = l;
			l = w;
			w = temp;
		}
		if (l > h)
		{
			temp = h;
			h = l;
			l = temp;
		}

		int powH = (h * h);
		int powWL = (w * w) + (l * l);

		if (powH == powWL)
		{
			std::cout << triangle << "\n";
		}
		else
		{
			std::cout << nonTriangle << "\n";
		}
		
	}

	return 0;
}