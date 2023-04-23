#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 뱀과 사다리 게임 - Graph 알고리즘
/// 기존 BFS에는 방향이 4방향이면 wheil문 안 for문을 4번 돌렸다.
/// 이번엔 주사위를 굴리므로 1부터 6까지 for문을 6번 실행시킨다.
/// recordMoveCnt 배열을 하나 만들어, 해당 배열을 board와 동일시하여 이동한 칸의 최소 횟수들을 적어놓는다.
/// </summary>

using namespace std;

vector<int> board(100, 0);
vector<int> recordMoveCnt(100, 0);
vector<bool> visited(100, false);

int BFS(int start, int moveCnt)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start, moveCnt));
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		int curMoveCnt = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int next = cur + i; //다음 이동
			int nextMoveCnt = curMoveCnt;
			if (next == 100)
			{
				nextMoveCnt += 1;
				return nextMoveCnt;

			}

			nextMoveCnt++;
			if (0 <= next && next < 100)
			{
				if (board[next] != 0)
				{
					next = board[next];
				}
				if (nextMoveCnt < recordMoveCnt[next])
				{
					recordMoveCnt[next] = nextMoveCnt;
					q.push({ next, nextMoveCnt });
				}
			}
		}
	}
}

int main(void)
{
	FastIO;

	int N(0), M(0); //사다리의 수 N, 뱀의 수 M
	std::cin >> N >> M;

	for (int i = 0; i < 100; i++)
	{
		recordMoveCnt[i] = 987654321;
	}

	for (int i = 0; i < N; i++)
	{
		int x, y;
		std::cin >> x >> y;
		board[x] = y;
	}

	for (int i = 0; i < M; i++)
	{
		int u, v;
		std::cin >> u >> v;
		board[u] = v;
	}

	int minMoveCnt = BFS(1, 0);
	std::cout << minMoveCnt << "\n";
	return 0;
}