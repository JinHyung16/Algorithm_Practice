#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 �峻��� ģ���� �ʿ��� - Graph �˰���
/// DFS�� ������ �ذ��Ѵ�.
/// O�� �� ����, X�� ��, I�� ������, P�� ����̴�.
/// 
/// �������� ķ�۽� ������ ������� �Է� �ǹǷ�, char�� ���� �Է� �޴´�.
/// �Է� �޴ٰ� 'I'�� ���� i�� j���� ���� startX, startY�� ���� �����صд�.
/// �� �� DFS�� ���鼭 stack�� �湮 ������ ���� �����صΰ�,
/// visited ���͸� ���� �湮�� ���� üũ�ϸ鼭 ����.
/// </summary>

using namespace std;

int N = 0, M = 0; //ķ�۽� ũ�� N * M
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