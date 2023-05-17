#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 �˰��� ����-�ʺ� �켱 Ž��4 - Graph �˰���
/// ���� �湮�� ���������� �������� �湮�Ѵ�.
/// ������ �׷�����, u�� v�� �� ��带 �����ϰ�
/// �̸� sort�Ͽ� ������������ �����Ѵ�.
/// 
/// depthVec�� ���̸� �����԰� ���ÿ� -1�� ���� �湮���� ���� ������� �ǹ��ϴ� �̰ɷ� üũ�Ѵ�.
/// visitNum�� �湮 ������ �����صд�.
/// ���������� �湮���� * ���̸� �� ���Ѱ��� ����ؾ� �Ѵ�.
/// </summary>

using namespace std;

vector<int> graph[100001];
long long depthVec[100001];
long long visitNum[100001];

void BFS(int start)
{
	int numCnt = 1;
	queue<int> q;
	q.push(start);
	depthVec[start] = 0;
	visitNum[start] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (depthVec[next] == -1)
			{
				//���� �湮���� ���� ����� ���̰� -1�̴�.
				depthVec[next] = depthVec[cur] + 1;
				numCnt += 1;
				visitNum[next] = numCnt;
				q.push(next);
			}
		}
	}

}

int main(void)
{
	FastIO;
	
	int N(0), M(0), R(0); //������ �� N, ������ �� M, ���� ���� R
	std::cin >> N >> M >> R;

	for (int i = 1; i <= M; i++)
	{
		int u(0), v(0);
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		std::sort(graph[i].begin(), graph[i].end());
	}

	memset(depthVec, -1, sizeof(depthVec));
	BFS(R);

	long long result(0);
	for (int i = 1; i <= N; i++)
	{
		result += (depthVec[i] * visitNum[i]);
	}
	std::cout << result << "\n";
	return 0;
}