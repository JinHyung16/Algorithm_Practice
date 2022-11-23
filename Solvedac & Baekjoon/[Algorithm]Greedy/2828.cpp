#include<iostream>

using namespace std;

/// <summary>
/// Silver5 사과 담기 게임 - Greedy 알고리즘
/// 그리디는 '최소한'의 키워드, optimal한 해를 구하자
/// 바구니 크기가 2부턴 사과위치가 범위 안에 있는지 체크하는게 포인트
/// </summary>


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//n이 전체 바닥 칸, m이 현재 내 위치
	int n = 0, m = 0;

	int newM = 0;
	int appleCount = 0;
	int applePos = 0;
	int moveCount = 0;

	std::cin >> n >> m;
	if (m > 1)
	{
		newM = m - 1;
	}

	std::cin >> appleCount;

	for (int i = 0; i < appleCount; i++)
	{
		std::cin >> applePos;

		//applePos가 바구니 범위 내 있는지 체크해서 있으면 moveLength 증가 안해도 된다
		if (m - newM <= applePos && applePos <= m)
		{
			continue;
		} 
		else if (m < applePos)
		{
			moveCount += applePos - m;
			m += (applePos - m); //현재 내 위치는 왼쪽 applePos는 오른쪽에 있으니 오른쪽으로 이동
		}
		else if (applePos < m)
		{
			moveCount += m - applePos - newM; //바구니 길이만큼 length증가가 아니라 해당 안에 있으니 무조건 1증가
			m -= (m - applePos - newM); //현재 내 위치가 오른쪽이고 applePos는 왼쪽에 있으니 왼쪽으로 이동
		}
	}

	std::cout << moveCount << "\n";
	return 0;
}