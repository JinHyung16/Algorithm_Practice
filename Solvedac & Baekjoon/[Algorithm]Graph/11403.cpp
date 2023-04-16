#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 경로 찾기 - Graph 알고리즘
/// 플로이드 와샬 알고리즘을 알게된 문제다.
/// 모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구해야하는 경우에 사용된다. 이때 한번에 구한다.
/// 
/// i행과 j열의 원소 (i,j)원소와 정점 n -> for(n to 점점수){for(i to 정점수){for(j to 정점수)}}
/// 기본 점화식은 distance[i,j] = min(distance[i,j], distance[i,n]+distance[n,j]))
/// </summary>

using namespace std;

vector<vector<int>> matrix(101, vector<int>(101, 10000));

int main(void)
{
	FastIO;
	
	int N(0); //정점의 개수 N
	std::cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> matrix[i][j];
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = 10000;
			}
		}
	}

	for (int n = 0; n < N; n++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				matrix[i][j] = std::min(matrix[i][j], matrix[i][n] + matrix[n][j]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] == 10000)
			{
				std::cout << 0 << " ";
			}
			else
			{
				std::cout << 1 << " ";
			}
		}
		std::cout << "\n";
	}

	return 0;
}