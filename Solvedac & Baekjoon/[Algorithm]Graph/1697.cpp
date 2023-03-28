#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���ٲ��� - �׷��� �˰���
/// BFS�� �̿��� Ǯ�̴�.
/// �������� ������ġ �������� +1, -1, *2 �̷��� �̵� �����ϴ� ������
/// �̵� ������ �������� �����̸鼭 moveCnt�� �����Ѵ�.
/// </summary>

using namespace std;

vector<bool> visited(100001, false);

int BFS(int start, int end)
{
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		int moveCnt = q.front().second;
		q.pop();

		if (cur == end)
		{
			return moveCnt;
			break;
		}

		if (0 <= (cur * 2) && (cur * 2) < 100001 && !visited[2 * cur])
		{
			visited[2 * cur] = true;
			q.push({ 2 * cur, moveCnt + 1 });
		}
		if (0 <= (cur + 1) && (cur + 1) < 100001 && !visited[cur + 1])
		{
			visited[cur + 1] = true;
			q.push({ cur + 1, moveCnt + 1 });
		}
		if (0 <= (cur - 1) && (cur - 1) < 100001 && !visited[cur - 1])
		{
			visited[cur - 1] = true;
			q.push({ cur - 1, moveCnt + 1 });
		}
		
	}

	return 0;
}

int main(void)
{
	FastIO;
	
	int N(0), K(0); //������ ��ġ N, ���� ��ġ K

	std::cin >> N >> K;

	std::cout << BFS(N, K) << "\n";
	return 0;
}