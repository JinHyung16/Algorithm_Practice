#include<iostream>
#include<vector>
#include<queue>


#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 양 - Graph 알고리즘
/// Row는 y축을 Col은 x축을 의미한다.
/// for i to R
///		for j to C
/// 이렇게 이중 for문을 돌면서 방문하지 않은 곳이면 BFS를 실행한다.
/// 
/// BFS에선 해당 map[y][x]의 양과 늑대 개수를 파악한다.
/// 그 후 BFS를 다 돌고 난 뒤, 양과 늑대 개수를 비교해 살아 남은 쪽만 total변수의 더해준다.
/// </summary>


int R = 0, C = 0; //행과 열의 수
int totalSheep = 0, totalWolf = 0; //최종 생존한 양과 늑대 수

char map[250][250] = { ' ', };
bool visited[250][250] = { false, };

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int y, int x)
{
	int wolf = 0, sheep = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while ( !q.empty() )
	{
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		if ( map[curR][curC] == 'v' )
			wolf++;
		if ( map[curR][curC] == 'o' ) 
			sheep++;

		for ( int i = 0; i < 4; i++ )
		{
			int nextR = curR + dy[i];
			int nextC = curC + dx[i];

			if ( 0 <= nextR && nextR < R && 0 <= nextC && nextC < C )
			{
				if ( map[nextR][nextC] != '#' && !visited[nextR][nextC] )
				{
					visited[nextR][nextC] = true;
					q.push(make_pair(nextR, nextC));
				}
			}
		}
	}

	if ( wolf < sheep )
		totalSheep += sheep;
	else
		totalWolf += wolf;
}

int main(void)
{
	FastIO;
	
	cin >> R >> C;
	for ( int i = 0; i < R; i++ )
	{
		for ( int j = 0; j < C; j++ )
		{ 
			cin >> map[i][j];
		}
	}
	
	for ( int i = 0; i < R; i++ )
	{
		for ( int j = 0; j < C; j++ )
		{
			if ( !visited[i][j] )
			{
				BFS(i, j);
			}
		}
	}

	cout << totalSheep << " " << totalWolf << "\n";

	return 0;
}