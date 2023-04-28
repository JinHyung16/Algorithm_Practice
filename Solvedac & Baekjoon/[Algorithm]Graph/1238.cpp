#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 ��Ƽ - Graph �˰���
/// Graph�� end������ time�� pair ���·� �־� �����صд�.
/// BFS�� �����ϸ鼭 �켱���� queue�� �Ÿ��� ū ������� ���������ؼ� ���� �� �ְ��ϰ�,
/// timeVec�� �� �������� �ɸ��� �ð����� �ִ����� �����صд�.
/// priority_queue���� {�ɸ��� �ð�, ���� ��ġ} �������� �����صд�.
/// 
/// while���� �����ϸ鼭, graph[curPos]�� ũ�⸸ŭ ���µ� �� �ǹ̴� 1�� ���� ����� ��� ��带 ���ڴٴ� �ǹ̴�.
/// �̷��� ���鼭 ���� �ð��� �迭�� ����� �ð����� ũ�� �н�, ������ ���� ��α��� �ɸ��� �ð��� ���� �ð��� ���ļ� �����صΰ�
/// pq�� �־�д�. �̷��� �ݺ��Ͽ� ���������� ���� �� �ð��� ����Ѵ�.
/// </summary>

using namespace std;

int N(0), M(0); //N���� �л�, M���� �ܹ��� ����
vector<pair<int, int>> graph[1001];
vector<int> timeVec(1001, 98765);
vector<int> resultTime(1001, 0);

void BFS_Dijkstra(int start)
{
	timeVec.clear();
	timeVec.resize(N + 1, 98765);
	timeVec[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int curTime = pq.top().first;
		int curPos = pq.top().second;
		pq.pop();

		if (timeVec[curPos] < curTime)
		{
			continue;
		}

		for (int i = 0; i < graph[curPos].size(); i++)
		{
			int nextPos = graph[curPos][i].first;
			int next_time = curTime + graph[curPos][i].second;

			if (next_time < timeVec[nextPos])
			{
				timeVec[nextPos] = next_time;
				pq.push(make_pair(next_time, nextPos));
			}
		}
	}
}

int main(void)
{
	FastIO;

	int X(0); //��� �л��� ������ X�� X���� ������ ���� �� �� �ִ�.
	std::cin >> N >> M >> X;

	for (int i = 0; i < M; i++)
	{
		int start(0), end(0), time(0);
		std::cin >> start >> end >> time;
		graph[start].push_back({ end,time });
	}

	for (int i = 1; i <= N; i++)
	{
		BFS_Dijkstra(i);
		resultTime[i] = timeVec[X];
	}
	BFS_Dijkstra(X);
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		resultTime[i] += timeVec[i];
		result = std::max(result, resultTime[i]);
	}
	std::cout << result << "\n";
	return 0;
}