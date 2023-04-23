#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 ��� ��ٸ� ���� - Graph �˰���
/// ���� BFS���� ������ 4�����̸� wheil�� �� for���� 4�� ���ȴ�.
/// �̹��� �ֻ����� �����Ƿ� 1���� 6���� for���� 6�� �����Ų��.
/// recordMoveCnt �迭�� �ϳ� �����, �ش� �迭�� board�� ���Ͻ��Ͽ� �̵��� ĭ�� �ּ� Ƚ������ ������´�.
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
			int next = cur + i; //���� �̵�
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

	int N(0), M(0); //��ٸ��� �� N, ���� �� M
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