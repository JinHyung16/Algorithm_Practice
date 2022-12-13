#include <iostream>
#include <vector>
#include <queue>

#define MAX_DISTANCE 987654321 //int���� �ִ�
using namespace std;

/// <summary>
/// Gold5 ��� ������ �Ÿ� - Graph �˰���
/// BFS�� �̿��ϸ� �Ÿ��� ���� ã�� �� ������,
/// DFS�� priority queue�� �̿��� ��Ʈ��ŷ �ϵ��� Ǯ��ô�.
/// ���� stack�� �̿��ϴµ� top�� �ִ°� �������� top�� ����� ���� �켱���� ť ���
/// </summary>

int n, m;
vector<pair<int, long long>> tree[1001]; //����� �� ���� �Ÿ� ���� ����
long long visitedDist[1001];

void ResetDistance()
{
	for (int i = 1; i <= n; i++)
	{
		visitedDist[i] = MAX_DISTANCE; //�Ÿ��� �ſ� ū ���� ����
	}
}

void FindDistance(int startNode, int endNode)
{
	priority_queue<pair<long long, int>> pq;
	pq.push(make_pair(0, startNode));

	ResetDistance();
	visitedDist[startNode] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		long long dis = -1 * pq.top().first;
		pq.pop();

		for (int i = 0; i < tree[cur].size(); i++)
		{
			int next = tree[cur][i].first;
			int curDis = tree[cur][i].second;

			if (curDis + dis < visitedDist[next])
			{
				visitedDist[next] = curDis + dis;
				pq.push(make_pair(-1 * visitedDist[next], next));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		int na, nb, dis;
		std::cin >> na >> nb >> dis;
		tree[na].push_back({ nb, dis });
		tree[nb].push_back({ na, dis });
	}

	for (int i = 0; i < m; i++)
	{
		int startNode, endNode;
		cin >> startNode >> endNode;
		FindDistance(startNode, endNode);
		std::cout << visitedDist[endNode] << std::endl;
	}
	return 0;
}