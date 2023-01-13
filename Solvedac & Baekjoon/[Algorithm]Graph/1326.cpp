#include<iostream>
#include<queue>

/// <summary>
/// Silver2 폴짝폴짝 - Graph 알고리즘
/// BFS를 이용한 문제 풀이
/// BFS함수에서 움직일 때, 방향이 아닌 rockBridge에 적힌 숫자만큼 이동한다
/// 이때, 앞으로도 가보고, 뒤로도 가는 등 갈 수 있는걸 체크해서 recordVisit에 +1한다
/// 최종적으로 recordVisit[end]가 0이면 온 적이 없단 소리고, 아니라면 여기를 왔던적이 있단 소리다.
/// </summary>

using namespace std;

int N(0); //정검다리 개수

int rockBridge[10001]; //징검다리 최대 개수가 10000이다.
bool visited[10001];
int recordVisit[10001];

void BFS(int start, int end)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == end)
		{
			return;
		}

		for (int i = cur + rockBridge[cur]; i <= N; i += rockBridge[cur])
		{
			if (!visited[i])
			{
				recordVisit[i] = recordVisit[cur] + 1;
				q.push(i);
				visited[i] = true;
			}
		}

		for (int i = cur - rockBridge[cur]; i >= 1; i -= rockBridge[cur])
		{
			if (!visited[i])
			{
				recordVisit[i] = recordVisit[cur] + 1;
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int start(0), end(0);

	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> rockBridge[i];
	}
	std::cin >> start >> end;

	if (start == end)
	{
		std::cout << 0 << std::endl;
		return 0;
	}

	BFS(start, end);

	if (recordVisit[end] == 0)
	{
		std::cout << -1 << std::endl;
	}
	else
	{
		std::cout << recordVisit[end] << std::endl;
	}
	return 0;
}