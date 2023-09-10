#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���Ĺ� ���ϱ� - �׷����̷� �˰���
/// DFS�� ���� ������ �ذ��Ѵ�.
/// �־��� �Է��� ���� ��, ��� ������ ���� DFS�� ���鼭 ���� ũ�渣 �޴´�.
/// DFS�� �� �������� ���� ũ��� 1�� �ʱ�ȭ ���ְ�, ���� ũ����� ���� �迭�� ��Ƶд�.
/// �� �� ���� ���� �� �������� �������� ������ �� �� ���� �տ��ִ� ���� ����Ѵ�.
/// </summary>

using namespace std;

int N = 0, M = 0, K = 0; //������ ���� N, ������ ���� M, ���Ĺ� �������� ���� K
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