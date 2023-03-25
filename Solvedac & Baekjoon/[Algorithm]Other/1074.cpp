#include<iostream>
#include<vector>
#include<string>
#include<math.h>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 Z - 분할 정복 알고리즘
/// 배열의 크기가 2^N * 2^N이다. 따라서 이를 한번에 다 돈다면 결국 O(N)걸린다.
/// 따라서 배열을 4개의 구역으로 나눈 뒤 어느 구역에 속하는지 판별하고,
/// 해당 구역만 탐색하도록 바꾼다.
/// 
/// 각 사분면별로 첫 시작 값이 1사분면은 0, 2사분면은 (mid*mid), 3사분면은(mid*mid*2) 4사분면은 (mid*mid*3)이다.
/// 문제에 주어진 표를 보고 4구역을 나눠서 첫 시작점 값을 보면 알 수 있다.
/// 
/// 즉 사분면을 판단했을 때와, 해당 사분면의 들어가서 탐색할 때의 값의 차이를 혼동하지 말자.
/// </summary>

using namespace std;

int Search(int x, int y, int n)
{
	if (n < 1)
	{
		return 0;
	}
	int mid = (int)pow(2, n - 1);

	//왼쪽 위 -> 오른쪽 위 -> 왼쪽 아래 -> 오른쪽 아래 순서대로 1 2 3 4분면이라 한다.
	if (x < mid && y < mid)
	{
		//1사분면 탐색
		return Search(x, y, n - 1);
	}
	else if (mid <= x && y < mid)
	{
		//2사분면 탐색
		return (mid * mid) + Search(x - mid, y, n - 1);
	}
	else if (x < mid && mid <= y)
	{
		//3사분면 탐색
		return (mid * mid * 2) + Search(x, y - mid, n - 1);
	}
	else
	{
		//4사분면 탐색
		return (mid * mid * 3) + Search(x - mid, y - mid, n - 1);
	}

}

int main(void)
{
	FastIO;

	int N(0), r(0), c(0); //크기 N, r행 c열
	std::cin >> N >> r >> c;

	int result = Search(c, r, N); //행이 y 열이 x를 의미

	std::cout << result << "\n";
	return 0;
}