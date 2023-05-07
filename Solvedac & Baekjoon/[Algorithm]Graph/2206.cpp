#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 벽 부수고 이동하기 - Graph 알고리즘
/// BFS를 이용해 해결한다.
/// 벽을 부수는게 있기에, queue에 벽을 부셨는지에 대한 여부까지 저장해둔다.
/// 
/// visited에는 방문한 지점에 대해 벽을 부순 상태와, 벽을 부수지 않은 상태별로 이동한 칸의 개수를 저장한다.
/// visited[y][x][0]은 벽을 부순 상태에서 해당 칸에 도착하는 데에 이동한 칸의 개수
/// visited[y][x][1]은 벽을 부수지 않은 상태에서 해당 칸에 도착하는 데에 이동한 칸에 개수
/// </summary>

using namespace std;

int N(0), M(0); //N*M 인접 행렬

vector<vector<int>> map(1000, vector<int>(1000, 0));
int visited[1000][1000][2];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int BFS(int x, int y)
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));
	visited[y][x][1] = 1;
	
	while (!q.empty())
	{
		int curX = q.front().first.second;
		int curY = q.front().first.first;
		int block = q.front().second; //1이 들어옴
		q.pop();

		if (curX == M - 1 && curY == N - 1)
		{
			return visited[curY][curX][block];
		}

		for (int i = 0; i < 4; i++)
		{
			int nextX = dx[i] + curX;
			int nextY = dy[i] + curY;
			if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N)
			{
				//다음 칸이 벽이고, 뚫을 수 있을 때
				if (map[nextY][nextX] == 1 && block)
				{
					q.push(make_pair(make_pair(nextY, nextX), 0));
					visited[nextY][nextX][block - 1] = visited[curY][curX][block] + 1;
				}
				//다음 칸이 벽이 아니고, 아직 방문한적이 없다면
				else if (map[nextY][nextX] == 0 && visited[nextY][nextX][block] == 0)
				{
					q.push(make_pair(make_pair(nextY, nextX), block));
					visited[nextY][nextX][block] = visited[curY][curX][block] + 1;
				}
			}
		}
	}

	return -1;
}

int main(void)
{
	FastIO;

	std::cin >> N >> M;
	char input(' ');
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> input;
			map[i][j] = input - '0';
		}
	}

	int result = BFS(0, 0);
	std::cout << result << "\n";
	return 0;
}