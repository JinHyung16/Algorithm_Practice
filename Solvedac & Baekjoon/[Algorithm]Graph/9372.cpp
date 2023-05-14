#include<iostream>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 상근이의 여행 - Graph 알고리즘
/// 1. 주어지는 비행기 스케줄은 항상 연결 그래프를 이룬다.
/// 2. 가중치가 존재하지 않는다.
/// 즉 이는 MST를 의미하는데, MST의 조건은 간선의 개수가 (노드 - 1)개다.
/// 
/// 현재 도시의 종류 N이 노드이므로,
/// 타야할 비행기 종류의 최소 개수 즉 간선은 N - 1하면 된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int T(0); //테스트 케이스
	int N(0), M(0); //국가의 수 N, 비행기의 종류 M
	int a(0), b(0); //비행기가 왕복하는 a와 b
	std::cin >> T;

	while (T--)
	{
		std::cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			std::cin >> a >> b;
		}
		std::cout << N - 1 << "\n";
	}

	return 0;
}