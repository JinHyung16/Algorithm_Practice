#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 방 배정하기 - 브루트포스 알고리즘
/// 3중 for문을 통해 A, B, C에 대해 값을 증가시키면서 찾는다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int A = 0, B = 0, C = 0; //방의 정원을 나타내는 서로다른 세 자연수 A, B, C
	int N = 0; //전체 학생 수 N
	std::cin >> A >> B >> C >> N;
	for ( int i = 0; i <= N; i++ )
	{
		int a = A * i;
		for ( int j = 0; j <= N; j++ )
		{
			int b = B * j;
			for ( int k = 0; k <= N; k++ )
			{
				int c = C * k;
				if ( a + b + c == N )
				{
					std::cout << "1" << "\n";
					return 0;
				}
				
			}
		}
	}

	std::cout << "0" << "\n";
	return 0;
}