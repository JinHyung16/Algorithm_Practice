#include<iostream>
#include<algorithm>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 병든 나이트 - 그리디 알고리즘
/// N에 따라 움직이는 횟수가 달라진다.
/// N=1면 어디든 이동 불가능하여 1
/// N=2면 이동 방법 2, 3번에 의해 (M-1)/2+1이다. +1은 처음 나이트 위치를 의미
/// 3 <= N이면 가로 길이에 따라 나뉜다.
/// 가로가 7칸 이상인 경우는 1, 2, 3, 4 이동방식 다 가능하여 총 M-2번 여행 가능
/// 가로가 7칸 미만이면 1, 4 이동방식을 사용하여 M칸 만큼 이동 가능하나 문제 조건에 의해 최대 4칸으로 가능
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, M = 0; //N*M 체스판, 세로 N 가로 M
	std::cin >> N >> M;

	int maxMoveCnt = 0;
	switch ( N )
	{
		case 1:
			maxMoveCnt = 1;
			break;
		case 2:
			maxMoveCnt = std::min(4, (M - 1) / 2 + 1);
			break;
		default:
			if ( M < 7 )
			{
				maxMoveCnt = std::min(M, 4);
			}
			else
			{
				maxMoveCnt = M - 2;
			}
			break;
	}

	std::cout << maxMoveCnt << "\n";
	return 0;
}	