#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 �ּҺ�� ���ϱ�2 - Graph �˰���
/// ���ͽ�Ʈ�� ������ �̿��� �ذ�
/// start���� ���� �������� �̵����� ��, beforeRoute[���� ����] = ���� ������ �־�д�.
/// �־�� ��θ� ������ ����Ѵ�.
/// </summary>

using namespace std;

vector<pair<int, int>> city[1001];
vector<int> costVec(1001, 987654321);
vector<int> route;
vector<int> beforeRoute(1001, 0);

void BFS_Dijkstra(int startNode)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, startNode));
	costVec[startNode] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if (costVec[cur] < curCost)
		{
			continue;
		}

		for (int i = 0; i < city[cur].size(); i++)
		{
			int next = city[cur][i].first;
			int nextCost = city[cur][i].second;

			if (curCost + nextCost < costVec[next])
			{
				costVec[next] = curCost + nextCost;
				pq.push(make_pair(costVec[next], next));
				beforeRoute[next] = cur;
			}
		}
	}
}

int main(void)
{
	FastIO;

	int N(0), M(0); //������ ���� N, ������ ���� M
	int s(0), e(0), c(0); //����, ����, ���
	std::cin >> N;
	std::cin >> M;

	while (M--)
	{
		std::cin >> s >> e >> c;
		city[s].push_back(make_pair(e, c));
	}

	int start(0), end(0);
	std::cin >> start >> end;

	BFS_Dijkstra(start);

	//before route�� �������� index�� ���� ���� ��Ʈ�� �־��.
	//�׷��� ������ route�� push�ϸ鼭 �ִ´�.
	int temp = end;
	while (temp)
	{
		route.push_back(temp);
		temp = beforeRoute[temp];
	}

	std::cout << costVec[end] << "\n";
	std::cout << route.size() << "\n";
	for (int i = route.size() - 1; 0 <= i; i--)
	{
		std::cout << route[i] << " ";
	}
	std::cout << "\n";

	return 0;
}