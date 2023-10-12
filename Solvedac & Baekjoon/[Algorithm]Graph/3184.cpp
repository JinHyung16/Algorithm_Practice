#include<iostream>
#include<vector>
#include<queue>


#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 �� - Graph �˰���
/// Row�� y���� Col�� x���� �ǹ��Ѵ�.
/// for i to R
///		for j to C
/// �̷��� ���� for���� ���鼭 �湮���� ���� ���̸� BFS�� �����Ѵ�.
/// 
/// BFS���� �ش� map[y][x]�� ��� ���� ������ �ľ��Ѵ�.
/// �� �� BFS�� �� ���� �� ��, ��� ���� ������ ���� ��� ���� �ʸ� total������ �����ش�.
/// </summary>


int R = 0, C = 0; //��� ���� ��
int totalSheep = 0, totalWolf = 0; //���� ������ ��� ���� ��

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