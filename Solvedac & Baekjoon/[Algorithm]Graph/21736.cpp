#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 헌내기는 친구가 필요해 - Graph 알고리즘
/// DFS로 문제를 해결한다.
/// O는 빈 공간, X는 벽, I는 도연이, P는 사람이다.
/// 
/// 문제에서 캠퍼스 정보는 공백없이 입력 되므로, char를 통해 입력 받는다.
/// 입력 받다가 'I'인 곳의 i와 j값을 통해 startX, startY의 값을 저장해둔다.
/// 그 후 DFS를 돌면서 stack의 방문 가능한 곳을 저장해두고,
/// visited 벡터를 통해 방문한 곳을 체크하면서 간다.
/// </summary>

using namespace std;

int N = 0, M = 0; //캠퍼스 크기 N * M
vector<vector<char>> campus(601, vector<char>(601, ' '));
vector<vector<bool>> visited(601, vector<bool>(601, false));

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int DFS(int sx, int sy)
{
	stack<pair<int, int>> stk;
	stk.push(make_pair(sx, sy));
	visited[sy][sx] = true;
	int meetCnt = 0;
	while ( !stk.empty() )
	{
		int curX = stk.top().first;
		int curY = stk.top().second;
		stk.pop();
		for ( int i = 0; i < 4; i++ )
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if ( nextX < 0 || M <= nextX || nextY < 0 || N <= nextY )
			{
				continue;
			}

			if ( campus[nextY][nextX] == 'X' )
			{
				continue;
			}
			if ( !visited[nextY][nextX] )
			{
				visited[nextY][nextX] = true;
				stk.push(make_pair(nextX, nextY));
				if ( campus[nextY][nextX] == 'P' )
				{
					meetCnt++;
				}
			}
		}
	}

	return meetCnt;
}
int main(void)
{
	FastIO;
	std::cin >> N >> M;

	int startX = 0, startY = 0;

	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < M; j++ )
		{
			std::cin >> campus[i][j];
			if ( campus[i][j] == 'I' )
			{
				startX = j;
				startY = i;
			}
		}
	}

	int result = DFS(startX, startY);

	if ( result == 0 )
	{
		std::cout << "TT" << "\n";
	}
	else
	{
		std::cout << result << "\n";
	}
	return 0;
}