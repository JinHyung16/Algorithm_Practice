#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold3 �� ����� - Graph �˰���
/// �������ķ� �ذ��ϸ� �ȴ�. ���� ����Ŭ�� ���� �׷������� ����
/// �л� ��ȣ A, B�� ������� �����µ� �̴� A�� B�տ� �����ϴ�
/// ����� A->B�� �׷����� �ȴ�.
/// inDegree �迭�� ������ ���� ���� ���� +1 ���ش�.
/// �� A, B�̸� �׷��� ������ A->B�̴� inDegree[B]++��.
/// �� �� for i to N���� ���鼭 inDegree�� ���� ���� queue�� �߰����ش�.
/// !queue.empty()���� ����. queue.empty()�� ����Ŭ�� ��������� �����Ѵ�.
/// </summary>

using namespace std;
vector<vector<int>> graph(32001);
int inDegree[32001]; //���� ���Ŀ� ���� ���� ���� �迭
vector<int> topologySortVec; //���� ���� �� ������ ���� ���� �迭

void TopologySort(int N)
{
	queue<int> q;

	for ( int i = 1; i <= N; i++ )
	{
		if ( !inDegree[i] )
		{
			q.push(i);
		}
	}

	while ( !q.empty() )
	{
		int cur = q.front();
		q.pop();
		topologySortVec.push_back(cur);
		//std::cout << cur << " ";
		for ( int i = 0; i < graph[cur].size(); i++ )
		{
			inDegree[graph[cur][i]]--;
			if ( !inDegree[graph[cur][i]] )
			{
				q.push(graph[cur][i]);
			}
		}
	}
}

int main(void)
{
	FastIO;

	int N = 0, M = 0; //������ �� N, Ű �� Ƚ�� M
	std::cin >> N >> M;
	for ( int i = 0; i < M; i++ )
	{
		int A = 0, B = 0; //�� �л� ��ȣ A, B
		std::cin >> A >> B;
		graph[A].push_back(B);
		inDegree[B]++;
	}

	TopologySort(N);

	for ( int i = 0; i < topologySortVec.size(); i++ )
	{
		std::cout << topologySortVec[i] << " ";
	}
	std::cout << "\n";
	return 0;
}	