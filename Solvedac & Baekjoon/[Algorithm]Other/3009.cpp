#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze3 네 번째 점 - 구현 알고리즘
/// 직사각형의 네 번째 점의 좌표를 구하려면
/// 주어진 3점의 좌표에서 x과 y축을 비교하여 같은게 2개 나왔다면
/// 남은 좌표가 해당 네 번째 좌표가 되어야 한다.
/// </summary>


int main(void)
{
	FastIO;

	int arrX[3] = { 0, };
	int arrY[3] = { 0, };

	int x = 0, y = 0;
	for ( int i = 0; i < 3; i++ )
	{
		cin >> arrX[i] >> arrY[i];
	}

	if ( arrX[0] == arrX[1] )
		x = arrX[2];
	else if ( arrX[1] == arrX[2] )
		x = arrX[0];
	else
		x = arrX[1];

	if ( arrY[0] == arrY[1] )
		y = arrY[2];
	else if ( arrY[1] == arrY[2] )
		y = arrY[0];
	else
		y = arrY[1];

	cout << x << " " << y << "\n";
	return 0;
}