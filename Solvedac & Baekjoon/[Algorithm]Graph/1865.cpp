#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 웜홀 - Graph 알고리즘
/// 웜홀의 경우 시간이 거꾸로 가니 저장할때 -를 곱해서 저장한다.
/// TimeTravel를 이용해 계산할 때, 파라미터로 지점 수와 시작 지점을 받는다.
/// 
/// 벨만 포드의 알고리즘은 최소비용을 구할 때 사용하는 알고리즘 중 하나로 다익스트라와 동일하게
/// 한 정점에서 다른 모든 정점으로 가는데 걸리는 최소 비용을 구하는데 사용한다.
/// 벨만 포드는 해당 간선의 출발 노드가 한번이라도 계산에 사용된 노드라면 업데이트 하는것이다.
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

	int T(0); //테스트 케이스 개수 T
	int  N(0), M(0), W(0); //지점의 수 N, 도로의 수 M, 웜홀의 수 W
	int start(0), end(0), time(0); //시점 지점, 도착 지점, 걸린 시간 의미

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
			adjacencyGraph[start].push_back(make_pair(end, -time)); //웜홀의 경우 시간 거꾸로 간다.
		}

		std::cout << TimeTravel(N, 1) << "\n";
	}
}