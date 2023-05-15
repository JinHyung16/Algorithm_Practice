#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 �˰��� ����, �ʺ� �켱 Ž�� 3 - Graph �˰���
/// 
/// 1. ������ �׷����� �����Ƿ�, 2���� �迭�� ����� �� ���� u�� v�� ���� ���� ������� ���´�.
/// 2. depth�� �����ϴ� �迭�� ����� �ʱ� ���� -1�� �����صд�. �ֳĸ� �湮���� ���� ����� ���̴� -1�̶� �߱⿡
///	   depth ����� ���ÿ� �湮 ���θ� üũ�ϵ��� �����Ѵ�.
/// 3. BFS�� ���鼭, start ������ depth�� 0�̸� ���� ��忡�� ����� ��忡 �� �����鼭 ���� ���̰� -1�̸� �湮���� �ʾ����Ƿ�
///    �ش� ������ �湮�ϸ鼭 depth���� ����� ������ depth���� + 1�� ���ָ鼭 �����Ѵ�.
/// </summary>

using namespace std;

vector<int> unDirectedGraph[100001];
vector<int> depthVec(100001, -1);

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	depthVec[start] = 0; //���� ����� ���̴� 0
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < unDirectedGraph[cur].size(); i++)
		{
			int next = unDirectedGraph[cur][i];
			if (depthVec[next] == -1)
			{
				depthVec[next] = depthVec[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	FastIO;

	int N(0), M(0), R(0); //������ ��  N, ������ �� M, ���� ���� R
	std::cin >> N >> M >> R;
	for(int i = 1; i <= M; i++)
	{
		int u(0), v(0); //���� u�� v
		std::cin >> u >> v;
		unDirectedGraph[u].push_back(v);
		unDirectedGraph[v].push_back(u);
	}

	BFS(R);
	for (int i = 1; i <= N; i++)
	{
		std::cout << depthVec[i] << "\n";
	}
	return 0;
}