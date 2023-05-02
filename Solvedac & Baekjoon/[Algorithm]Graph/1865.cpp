#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 ��Ȧ - Graph �˰���
/// ��Ȧ�� ��� �ð��� �Ųٷ� ���� �����Ҷ� -�� ���ؼ� �����Ѵ�.
/// TimeTravel�� �̿��� ����� ��, �Ķ���ͷ� ���� ���� ���� ������ �޴´�.
/// 
/// ���� ������ �˰����� �ּҺ���� ���� �� ����ϴ� �˰��� �� �ϳ��� ���ͽ�Ʈ��� �����ϰ�
/// �� �������� �ٸ� ��� �������� ���µ� �ɸ��� �ּ� ����� ���ϴµ� ����Ѵ�.
/// ���� ����� �ش� ������ ��� ��尡 �ѹ��̶� ��꿡 ���� ����� ������Ʈ �ϴ°��̴�.
/// </summary>

using namespace std;

vector<int> distVec(501, 987654321);
vector<pair<int, int>> adjacencyGraph[501];

string TimeTravel(int nodeCnt, int start)
{
	distVec[start] = 0;
	bool isUpdateTime = false;
	
	for (int  n = 0; n < nodeCnt; n++)
	{
		isUpdateTime = false;
		for (int i = 1; i <= nodeCnt; i++)
		{
			for (int j = 0; j < adjacencyGraph[i].size(); j++)
			{
				int next = adjacencyGraph[i][j].first;
				int time = adjacencyGraph[i][j].second;

				if (time + distVec[i] < distVec[next])
				{
					distVec[next] = time + distVec[i];
					isUpdateTime = true;
				}
			}
		}

		if (!isUpdateTime)
		{
			break;
		}
	}

	if (isUpdateTime)
	{
		return "YES";
	}
	else
	{
		return "NO";
	}
}

int main(void)
{
	FastIO;

	int T(0); //�׽�Ʈ ���̽� ���� T
	int  N(0), M(0), W(0); //������ �� N, ������ �� M, ��Ȧ�� �� W
	int start(0), end(0), time(0); //���� ����, ���� ����, �ɸ� �ð� �ǹ�

	std::cin >> T;
	while (T--)
	{
		std::cin >> N >> M >> W;

		for (int i = 0; i <= N; i++)
		{
			adjacencyGraph[i].clear();
			distVec[i] = 987654321;
		}

		for (int i = 0; i < M; i++)
		{
			std::cin >> start >> end >> time;
			adjacencyGraph[start].push_back(make_pair(end, time));
			adjacencyGraph[end].push_back(make_pair(start, time));
		}

		for (int i = 0; i < W; i++)
		{
			std::cin >> start >> end >> time;
			adjacencyGraph[start].push_back(make_pair(end, -time)); //��Ȧ�� ��� �ð� �Ųٷ� ����.
		}

		std::cout << TimeTravel(N, 1) << "\n";
	}
}