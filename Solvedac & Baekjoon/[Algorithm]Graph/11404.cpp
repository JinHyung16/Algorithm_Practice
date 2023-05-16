#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 플로이드 - Graph 알고리즘
/// 플로이드 워셜 알고리즘을 이용해 해결한다.
/// 플로이드 워셜은 한 번 실행하여 모든 노드 간 최단 경로를 구할 때 사용한다.
/// 음의 간선에 대해서도 사용할 수 있으며 시간 복잡도는 O(n^3)으로 그래프의 크기가 작은 경우에 유용하다.
/// </summary>

using namespace std;

vector<vector<int>> cities(101, vector<int>(101, 0));

int main(void)
{
	FastIO;
	
	int n(0), m(0); //도시의 수 n, 버스의 개수 m
	std::cin >> n;
	std::cin >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				cities[i][j] = 0;
			}
			else
			{
				cities[i][j] = 987654321;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a(0), b(0), c(0); //시작 도시 a, 도착 도시 b, 비용 c
		std::cin >> a >> b >> c;
		cities[a][b] = std::min(cities[a][b], c);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cities[i][j] = std::min(cities[i][j], cities[i][k] + cities[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cities[i][j] == 987654321)
			{
				std::cout << 0 << " ";
			}
			else
			{
				std::cout << cities[i][j] << " ";
			}
		}
		std::cout << "\n";
	}

	return 0;
}