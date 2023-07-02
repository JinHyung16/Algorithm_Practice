#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 그림 - Graph 알고리즘
/// DFS를 이용한 풀이다.
/// dfs는 한 분기점에 대해 끝까지 가봐야한다.
/// 1) 초기 입력받은 n, m에 대해 2중 for문을 돌면서 i, j번째에 대해 DFS를 실행하면서 그림의 총 개수를 찾는다.
/// 2) DFS내에선, 해당 i,j 번째에서 인접한 그림이 있는지 체크하면서 영역의 넓이를 찾는다.
/// 
/// 이렇게 2개의 과정을 걸쳤으면 마지막에 그림이 존재한지 체크하고, 이에 맞춰 출력한다.
/// </summary>

using namespace std;

int n = 0, m = 0; //도화지 세로 n, 가로 m
vector<vector<int>> paper(501, vector<int>(501, 0));
vector<vector<bool>> visited(501, vector<bool>(501, false));
vector<int> drawings; //완성된 그림들을 담아둘 배열
int drawSize = 1;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void DFS(int x, int y)
{
	visited[y][x] = true;

	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || m < nx || ny < 0 || n < ny)
		{
			continue;
		}
		if(!visited[ny][nx] && paper[ny][nx] == 1)
		{
			visited[ny][nx] = true;
			drawSize ++;
			DFS(nx, ny);
		}
	}
}

int main(void)
{
	FastIO;

	std::cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			std::cin >> paper[i][j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(paper[i][j] == 1 && !visited[i][j])
			{
				DFS(j, i);
				drawings.push_back(drawSize);
				drawSize = 1;
			}
		}
	}

	std::sort(drawings.rbegin(), drawings.rend());

	int cnt = drawings.size() ? drawings.size() : 0; //drawings.size()가 있으면 그걸, 아니면 0출력

	std::cout << cnt << "\n";

	//그림이 없다면 0, 있으면 가장 큰 넓이 출력
	if( cnt == 0)
	{
		std::cout << 0 << "\n";	
	}
	else
	{
		std::cout << drawings[0] << "\n";
	}
	
	return 0;
}