#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 트리 만들기 - 트리 알고리즘
/// 트리의 특성을 파악해보자, 리프 노드는 차수가 1인 노드를 의미한다.
/// 따라서 n-m까지 이어지게 노드를 붙이다가, m개의 라프가 필요하다면 n-m 노드 뒤에 하나씩 붙인다.
/// ex)n=4, m=2의 경우
/// 0 -> 1- > 2 -> 3 순서로 연결하면 노드 2번과 3번의 경우 리프고 리프 2개를 만족한다.
/// 
/// ex)n=4, m=3의 경우
/// 0 -> 1 -> 2
///	       -> 3
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int n = 0, m = 0; //n개의 노드, m개의 리프
	std::cin >> n >> m;

	for(int i = 0; i < n - 1; i++)
	{
		if(i < n - m)
		{
			//n-m까지 노드를 이어 붙인다.
			std::cout << i << " " << i + 1 << "\n";
		}
		else
		{
			//n-m 이후부터 노드는 n-m 이후 슷자에 노드를 붙인다.
			std::cout << n - m << " " << i + 1 << "\n";
		}
	}
	
	return 0;
}