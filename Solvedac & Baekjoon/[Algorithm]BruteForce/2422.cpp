#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 한윤정이 이탈리아에 가서 아이스크림을 사먹는데 - 브루트포스 알고리즘
/// N값이 작으니 3중 for문을 돌면서 ij, jk, ik의 값이 있다면 패스하고 아니면 result를 증가시킨다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, M = 0; //아이스크림 종류 N, M은 섞어먹으면 안 되는 조합의 개수
	std::cin >> N >> M;

	vector<vector<bool>> icecreams(201, vector<bool>(201, false));
	int result = 0;
	for ( int i = 0; i < M; i++ )
	{
		int a = 0, b = 0;
		std::cin >> a >> b;
		icecreams[a][b] = true;
		icecreams[b][a] = true;
	}

	for ( int i = 1; i <= N - 2; i++ )
	{
		for ( int j = i + 1; j <= N - 1; j++ )
		{
			for ( int k = j + 1; k <= N; k++ )
			{
				if ( icecreams[i][j] || icecreams[j][k] || icecreams[i][k] )
				{
					continue;
				}
				result++;
			}
		}
	}

	std::cout << result << "\n";
	return 0;
}