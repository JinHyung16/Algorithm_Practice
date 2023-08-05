#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 수들의 합 2 - 브루트포스 알고리즘
/// sequence 배열의 수들을 저장한다.
/// 그 후 2중 for문을 통해, sum의 합을 저장하고,
/// sum == M인 경우 경우의 수를 증가시키고, sum = 0으로 초기화 한 뒤 break한다.
/// 이때 안쪽 for문을 다 돌았는데 sum != 0이라면 항상 sum = 0으로 초기화 해준다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, M = 0; //N개의 수로 된 수열의 합 M
	std::cin >> N >> M;

	vector<int> sequence(N + 1, 0); //sequence 배열
	int sum = 0; //sequence[i] + sequence[j]의 합
	int cnt = 0; //sum == M을 만족하는 경우의 수 개수

	for ( int i = 0; i < N; i++ )
	{
		std::cin >> sequence[i];
	}

	for ( int i = 0; i < N; i++ )
	{
		for ( int j = i; j < N; j++ )
		{
			sum += sequence[j];
			if ( sum == M )
			{
				cnt++;
				sum = 0;
				break;
			}
		}
		if ( sum != 0 )
		{
			sum = 0;
		}
	}

	std::cout << cnt << "\n";
	return 0;
}