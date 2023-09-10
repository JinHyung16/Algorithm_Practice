#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 음식물 피하기 - 그래프이론 알고리즘
/// DFS를 통해 문제를 해결한다.
/// 주어진 입력을 받은 뒤, 재귀 개념을 통해 DFS를 돌면서 음식 크길르 받는다.
/// DFS를 다 돌때마다 음식 크기는 1로 초기화 해주고, 음식 크기들을 따로 배열에 담아둔다.
/// 그 후 가로 세로 다 돌았으면 오름차순 정렬을 한 뒤 가장 앞에있는 값을 출력한다.
/// </summary>

using namespace std;

int N = 0, M = 0, K = 0; //세로의 길이 N, 가로의 길이 M, 음식물 쓰레기의 개수 K
vector<vector<int>> map(110, vector<int>(110, 0));
vector<vector<bool>> visited(110, vector<bool>(110, false));
vector<int> foodVec;
int foodSize = 1;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void DFS(int x, int y)
{
	visited[y][x] = true;

	for ( int i = 0; i < 4; i++ )
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if ( nx < 0 || M < nx || ny < 0 || N < ny )
		{
			continue;
		}
		if ( map[ny][nx] == 1 && !visited[ny][nx] )
		{
			visited[ny][nx] = true;
			foodSize++;
			DFS(nx, ny);
		}
	}
}

int main(void)
{
	FastIO;
	
	std::cin >> N >> M >> K;
	for ( int i = 0; i < K; i++ )
	{
		int r = 0, c = 0;
		std::cin >> r >> c;
		map[r][c] = 1;
	}

	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= M; j++ )
		{
			if ( map[i][j] == 1 && !visited[i][j] )
			{
				DFS(j, i);
				foodVec.push_back(foodSize);
				foodSize = 1;
			}
		}
	}

	std::sort(foodVec.rbegin(), foodVec.rend());
	std::cout << foodVec[0] << "\n";
	return 0;
}