#include<iostream>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 암기왕 - 자료구조 알고리즘
/// set을 이용해 문제를 해결한다.
/// set의 수첩1의 값들을 넣어두고, 2에서 입력받을 때 1에서 계속 찾아간다.
/// 이 문제는 2초만에 해결해야 하므로 O(longN)이 걸리는 탐색을 이용하자
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int T = 0; //테스트 케이스의 개수 T
	int N = 0, M = 0; //수첩 1의 적어 놓은 정수 개수 N, 수첩 2의 적어 놓은 정수 개수 M
	std::cin >> T;
	while ( T-- )
	{
		set<int> note;
		std::cin >> N;
		for ( int i = 0; i < N; i++ )
		{
			int input = 0;
			std::cin >> input;
			note.insert(input);
		}
		std::cin >> M;
		for ( int i = 0; i < M; i++ )
		{
			int input = 0;
			std::cin >> input;
			if ( note.find(input) != note.end())
			{
				std::cout << "1" << "\n";
			}
			else
			{
				std::cout << "0" << "\n";
			}
		}
	}
	return 0;
}