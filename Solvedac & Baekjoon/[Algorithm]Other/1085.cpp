#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 직사각형에서 탈출 - 수학 알고리즘
/// (0,0)에서 (w,h)까지 직사각형을 그리면 가로는 w, 세로는 h다.
/// 본인의 위치 (x,y)에서 이 직사각형 변의 일직선으로 선을 그릴때 가장 짧은 길이를 찾으면 된다.
/// 1)x 값
/// 2)y 값
/// 3)h-y값
/// 4)w-x값
/// 이렇게 4개중 최솟값을 찾는다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int x(0), y(0), w(0), h(0);
	std::cin >> x >> y >> w >> h;

	int widthMin = std::min(x, w - x);
	int heightMin = std::min(y, h - y);

	int result = std::min(widthMin, heightMin);
	std::cout << result << "\n";
	return 0;
}