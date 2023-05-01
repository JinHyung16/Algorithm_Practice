#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 �ּҺ�� ���ϱ� - Graph �˰���
/// ���ͽ�Ʈ�� �̿��� Ǯ�̴�.
/// ���ͽ�Ʈ�� �˰����� �ϳ��� �������� �ٸ� ��� �������� �� �� �ִ� �ִ� ��θ� �̾߱��Ѵ�.
/// </summary>

using namespace std;

vector<pair<int, int>> city[1001];
vector<int> costVec(1001, 987654321);

void BFS_Dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	costVec[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		//costVect�� �� �ִ��̸� ���� �˻���ϰ� �Ѱܵ��ȴ�. �ֳĸ� �̹� �װ� �ּ� ����̴ϱ�.
		if (costVec[cur] < curCost)
		{
			continue;
		}

		for (int i = 0; i < city[cur].size(); i++)
		{
			int next = city[cur][i].first;
			int nextCost = curCost + city[cur][i].second;

			if (nextCost < costVec[next])
			{
				costVec[next] = nextCost;
				pq.push(make_pair(costVec[next], next));
			}
		}
	}
}
int main(void)
{
	FastIO;
	
	int N(0), M(0); //N���� ���� M���� ����
	std::cin >> N >> M;

	while (M--)
	{
		int start(0), end(0), cost(0);
		std::cin >> start >> end >> cost;
		city[start].push_back(make_pair(end, cost));
	}
	int S(0), E(0); //������� ������
	std::cin >> S >> E;

	BFS_Dijkstra(S);

	std::cout << costVec[E] << "\n";
	return 0;
}