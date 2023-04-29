#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 Ư���� �ִ� ��� - Graph �˰���
/// ���ͽ�Ʈ�� Ȱ���Ͽ� �ذ��Ѵ�.
/// �־��� �� ���� V1, V2�� ���� ��Ʈ1: start -> v1 -> v2 -> N ��Ʈ2: start -> v2 -> v1 -> N
/// 1. start -> v1 �� start -> v2������ �Ÿ��� ���� ���ͽ�Ʈ��
/// 2. v1 -> v2������ �Ÿ��� ���� ���ͽ�Ʈ���ε� ���⼭ ��������� v2 -> v1�� �ȱ��ص� ������.
/// 3. v2 -> N�� ���ϱ� ���� ���ͽ�Ʈ��� v1->v2�� ���� �� ���� �� ������ �н�
/// �̷��� ���ͽ�Ʈ�� ���� ������ ���� �����صΰ�, �� �� ��Ʈ�� �� ������ ���Ѵ�.
/// </summary>

using namespace std;

int N(0), E(0); //������ ���� N, ������ ���� E
int V1(0), V2(0);
vector<pair<int, int>> graph[801];
vector<int> distVec(801, 0);

void DistanceReset()
{
	for (int i = 0; i <= N; i++)
	{
		distVec[i] = 987654321;
	}
}

void BFS_Dijkstar(int start)
{
	DistanceReset();
	distVec[start] = 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	
	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int curPos = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[curPos].size(); i++)
		{
			int nextPos = graph[curPos][i].first;
			int nextDist = graph[curPos][i].second;

			if (nextDist + curDist < distVec[nextPos])
			{
				distVec[nextPos] = nextDist + curDist;
				pq.push(make_pair(distVec[nextPos], nextPos));
			}
		}
	}
}

int main(void)
{
	FastIO;

	int result(987654321);

	std::cin >> N >> E;

	while(E--)
	{
		int a(0), b(0), c(0);
		std::cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	std::cin >> V1 >> V2;

	BFS_Dijkstar(1);
	int startToV1 = distVec[V1];
	int startToV2 = distVec[V2];

	BFS_Dijkstar(V1);
	int v1ToV2 = distVec[V2]; //v2ToV1�̶� �Ÿ��� ����. �ֳĸ� ����� �׷����ϱ�
	int v1ToN = distVec[N];

	BFS_Dijkstar(V2);
	int v2ToN = distVec[N];

	result = std::min(result, (startToV1 + v1ToV2 + v2ToN));
	result = std::min(result, (startToV2 + v1ToV2 + v1ToN));

	if (v1ToV2 == 987654321 || result == 987654321)
	{
		std::cout << -1 << "\n";
	}
	else 
	{
		std::cout << result << "\n";
	}
	return 0;
}