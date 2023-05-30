#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 �ּ� ���д� Ʈ�� - Graph �˰���
/// ���д� Ʈ���� ��� ������ ����Ǿ� �����Ƿ�, �Է½� ��� ������ �̾��ش�.
/// MST �ذ�� �� ������ �̿��Ѵ�. �׷��Ƿ� priority_queue�� �ʿ��ϴ�.
/// ���� ���� V, ���� ���� E�� ���� ������ ���� �ſ� ������ �����Ѱ� �����̸�
/// O(ElogV)��ŭ �ɸ���.
/// </summary>

using namespace std;

vector<pair<int, int>> graph[10001];
vector<bool> visited(10001, false);
long long mstCost = 0;

void MST_Prim(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start)); //cost�� ������ �������� �����ϱ� ���� (�ڽ�Ʈ, ��� ��ġ)������ ����

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		//�湮�� ���� �׳� �ѱ��, �ƴ϶�� minCost�� ���ϱ�
		if (visited[cur])
		{
			continue;
		}

		visited[cur] = true;
		mstCost += curCost;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second;
			
			pq.push(make_pair(nextCost, next));
		}
	}
}

int main(void)
{
	FastIO;

	int V(0), E(0); //������ ���� V, ������ ���� E
	std::cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int a(0), b(0), c(0); //a���� b���� ������ ����ġ c
		std::cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	MST_Prim(1);
	
	std::cout << mstCost << "\n";
	return 0;
}
