#include<iostream>
#include<vector>
#include<queue>


#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver1 데스 나이트 - Graph 알고리즘
/// N크기의 2차원 maps을 만들고 그 내부를 -1로 초기화 한다.
/// BFS를 돌면서 시작 위치를 0으로 바꾼다.
/// 이동 가능한 다음 방향의 map에 이동하고 난 뒤 이전 map의 저장된 값에서 + 1한다.
/// 이렇게 하면 2차원 배열 1개로도 해결할 수 있다.
/// </summary>


vector<vector<int>> maps;

int dr[6] = { -2, -2, 0, 0, 2, 2 }; // row 방향 direct
int dc[6] = { -1, +1, -2, +2, -1, +1 }; // col 방향 direct

int BFS(int r1, int c1, int r2, int c2, int N)
{
	queue<pair<int, int>> q;
	q.push(make_pair(r1, c1));
	maps[r1][c1] = 0;

	while (!q.empty())
	{
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		if (curR == r2 && curC == c2)
		{
			return maps[curR][curC];
		}

		for (int i = 0; i < 6; i++)
		{
			int nextR = curR + dr[i];
			int nextC = curC + dc[i];
			
			if (0 <= nextR && nextR < N && 0 <= nextC && nextC < N)
			{
				if (maps[nextR][nextC] == -1)
				{
					maps[nextR][nextC] = maps[curR][curC] + 1;
					q.push(make_pair(nextR, nextC));
				}
			}
		}
	}

	return -1;
}

int main(void)
{
	FastIO;

	int N = 0; // 체스판의 크기 N
	cin >> N;
	maps.resize(N, vector<int>(N, -1));

	int r1 = 0, c1 = 0, r2 = 0, c2 = 0; // 데스 나이트 (r1, c1) -> (r2, c2)로 이동
	cin >> r1 >> c1 >> r2 >> c2;

	cout << BFS(r1, c1, r2, c2, N) << "\n";

	return 0;
}