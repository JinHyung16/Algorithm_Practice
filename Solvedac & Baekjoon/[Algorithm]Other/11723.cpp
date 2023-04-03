#include<iostream>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 집합 - 브루트포스 알고리즘
/// 두가지 방법으로 해결할 수 있다.
/// 1) 배열을 만들어 문제 조건에 맞춰 해결
/// 2) 비트마스크 문제로 해결
/// 비트 마스크 관련된 공부는 https://rebro.kr/63 참고했다.
/// 비트 마스크는 int는 4byte로 8bit을 의미 이때 이 bit를 이용하는것이다.
/// 컴퓨터 구조때 배운 연산 Not, Xor, And, Or, Shift 연산 개념을 활용한다.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;
	
	int M(0); //수행해야 하는 연산의 수
	string input;
	int bit(0), val(0);
	std::cin >> M;
	while (M--)
	{
		std::cin >> input;
		if (input == "add")
		{
			std::cin >> val;
			bit |= (1 << val);
		}
		else if (input == "remove")
		{
			std::cin >> val;
			bit &= ~(1 << val);
		}
		else if (input == "check")
		{
			std::cin >> val;
			if (bit & (1 << val))
			{
				std::cout << 1 << "\n";
			}
			else
			{
				std::cout << 0 << "\n";
			}
		}
		else if (input == "toggle")
		{
			std::cin >> val;
			bit ^= (1 << val);
		}
		else if (input == "all")
		{
			//21을 비트로 바꿔 왼쪽 쉬프트 1칸 후 1을 빼므로 1~20까지 표현
			bit = (1 << 21) - 1;
		}
		else if (input == "empty")
		{
			bit = 0;
		}
	}
	return 0;
}