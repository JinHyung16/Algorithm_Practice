#include<iostream>
#include<math.h>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 하노이 탑 이동 순서 - 재귀 알고리즘
/// 하노이의 탑 옮겨서 쌓는 시간은 원판 개수 N에대해 2^N - 1이다.
/// 
/// 탑 쌓는 순서 (시작 1번째, 원판 수 N개)
/// 1. N-1개의 원판을 1번 장대에서 3번을 거쳐 2번 장대로 옮긴다.
/// 2-1. 1번 장대에 있는 맨 아래 원판을 3번 장대로 옮긴 후,
/// 2-2. 2번 장대에 있는 N-1개의 원판을 1번 장대를 거쳐 3번 장대로 옮겨 올려놓는다.
/// 
/// pow 함수는 #include<math.h>에 있으니 꼭 선언하자!
/// </summary>

using namespace std;

void Hanoi(int first, int second, int third, int cnt)
{
	if (cnt == 1)
	{
		std::cout << first << " " << third << "\n";
	}
	else
	{
		Hanoi(first, third, second, cnt - 1); //1번 장대에 있는걸 3번을 걸쳐 2번 장대로 옮기기
		std::cout << first << " " << third << "\n";
		Hanoi(second, first, third, cnt - 1); //ㅈ번 장대에 있는 N-1개의 원판을 1번 장대를 거쳐 3번 장대로 옮기기
	}
}

int main(void)
{
	FastIO;

	int plateCount(0);
	std::cin >> plateCount;
	std::cout << (int)pow(2, plateCount) - 1 << "\n";
	Hanoi(1, 2, 3, plateCount);
	return 0;
}