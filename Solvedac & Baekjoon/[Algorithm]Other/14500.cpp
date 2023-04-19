#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 테트로미노 - 브루트포스 알고리즘
/// DFS와 재귀를 이용해 해결
/// ㅜ자 모양을 제외하곤 나머진 회전시키거나 대칭을 시켰을때 아무리 깊어봐야 depth가 3이다.
/// 따라서 T자만 따로 ㅓ, ㅏ, ㅗ, ㅜ로 나눠 구해주고 나머지 도형들은 depth가 3일때 값을 가져와 구해준다.
/// 
/// ㅗ모양을 기준으로 각 모양들을 회전시켜 생각하되 이때 기준은 [0]을 기준으로 회전시켰다고 가정하여 좌표 생각한다.
///    [3]
/// [0][1][2] 모양에서 [0]이 항상 좌표로 (y,x)다
/// 
/// ㅜ모양에서 각 회전시킨 모양 좌표 생각할때 아래를 참고한다. N이 세로, M이 가로라고 생각하여 N=y랑 M=x와 대응된다.
/// [0][1][2]  의 모양이면 [0]은 (y,x)이므로 [3]은 y-1이고, [2]는 x+2다. 이 모양의 기준은 0<=y-1 && x+2 < M 여야 가능하다
///    [3]     따라서 이때 maxSum을 구하기 위해선 [0]+[1]+[2]+[3]을 진행하여 [y][x] + [y][x+1] + [y][x+2] + [y-1][x+1]한다.
/// 
/// ㅓ모양은 다음과 같은 순서로, ㅏ모양은 다음과 같은 순서가 되므로 이에 맞춰 (y,x)를 찾자
///    [2]                   [2]
/// [3][1]                   [1][3]
///    [0]                   [0]
/// </summary>

using namespace std;

int N(0), M(0); //종이의 크기 N*M
vector<vector<int>> paper(501, vector<int>(501, 0));
vector<vector<bool>> visited(501, vector<bool>(501, false));
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int maxSum = -98765;


void TShape(int x, int y)
{
	//ㅜ 모양
	if (x + 2 < M && 0 <= y - 1)
	{
		maxSum = std::max(maxSum, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y - 1][x + 1]);
	}

	//ㅗ 모양
	if (x + 2 < M && y + 1 < N)
	{
		maxSum = std::max(maxSum, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y + 1][x + 1]);
	}

	//ㅓ 모양
	if (0 <= x - 1 && y + 2 < N)
	{
		maxSum = std::max(maxSum, paper[y][x] + paper[y + 1][x] + paper[y + 2][x] + paper[y + 1][x - 1]);
	}

	//ㅏ 모양
	if (x + 1 < M && y + 2 < N)
	{
		maxSum = std::max(maxSum, paper[y][x] + paper[y + 1][x] + paper[y + 2][x] + paper[y + 1][x + 1]);
	}
}

void Tetris(int x, int y, int depth, int sum)
{
	if (depth == 3)
	{
		maxSum = std::max(maxSum, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N)
		{
			if (!visited[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				Tetris(nextX, nextY, depth + 1, sum + paper[nextY][nextX]);
				visited[nextY][nextX] = false;
			}
		}
	}
}
int main(void)
{
	FastIO;
	
	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> paper[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			TShape(j, i);
			visited[i][j] = true;
			Tetris(j, i, 0, paper[i][j]);
			visited[i][j] = false;
		}
	}

	std::cout << maxSum << "\n";
	return 0;
}