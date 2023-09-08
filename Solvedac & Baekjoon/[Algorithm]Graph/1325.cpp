#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ȿ������ ��ŷ - �׷����̷� �˰���
/// BFS�� ���� ������ �ذ��Ѵ�.
/// ���� A�� B�� �ŷ��Ѵ� ������, vector[B].push_back(A);�� �Ѵ�. �׷��� B�� ���� �� A���� BFS Ž���� �����ϴ�.
/// �� �� Ž���� �����ϸ鼭 Ž���� ������ ������ ��ŷ�� Ƚ���� ī����Ͽ� �̸� N���� for���� ������.
/// �̶� ī��Ʈ Ƚ����, ���� ������ ���� vector<pair<int,int>>�� �����صд�.
/// �� �� Ž���� �� ������ ���� ū Ž�� Ƚ���� ã��,
/// for���� ���� ī��Ʈ Ƚ����, ���� ������ ���� ������ �迭�� �� Ž���ϸ鼭 ���� ū Ž�� Ƚ���� ���� ��츸 ����Ѵ�.
/// </summary>

using namespace std;

int N = 0, M = 0;
vector<int> computer[10001];
vector<bool> visited(10001, false);
vector<pair<int, int>> hackPC;
int canHackCnt = 1;

void BFS(int start)
{
	visited[start] = true;
	queue<int> q;
	q.push(start);

	while ( !q.empty() )
	{
		int cur = q.front();
		q.pop();

		for ( int i = 0; i < computer[cur].size(); i++ )
		{
			int next = computer[cur][i];

			if ( !visited[next] )
			{
				visited[next] = true;
				q.push(next);
				canHackCnt++;
			}
		}
	}
}

void Reset()
{
	for ( int i = 0; i <= N; i++ )
	{
		visited[i] = false;
	}
}

int main(void)
{
	FastIO;
	
	std::cin >> N >> M;
	for ( int i = 0; i < M; i++ )
	{
		int A = 0, B = 0;
		std::cin >> A >> B;
		computer[B].push_back(A);
	}

	for ( int i = 1; i <= N; i++ )
	{
		BFS(i);
		Reset();
		hackPC.push_back(make_pair(i, canHackCnt));
		canHackCnt = 1;
	}

	int maxHackCnt = -1;
	for ( int i = 0; i < hackPC.size(); i++ )
	{
		if ( maxHackCnt < hackPC[i].second )
		{
			maxHackCnt = hackPC[i].second;
		}
	}

	for ( int i = 0; i < hackPC.size(); i++ )
	{
		if ( hackPC[i].second == maxHackCnt )
		{
			std::cout << hackPC[i].first << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}