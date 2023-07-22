#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ���� a�� k�� ����� - Graph �˰���
/// �� ������ �׷����� ������ �ü��� �ٲ�� �Ѵ�.
/// ��� �� N�� ���� N+1�� N*2�� ���� �Ÿ��� 1�� ������ �ְ�,
/// A���� K������ �ּ� �Ÿ��� ���ϴ� ������� �����Ѵ�.
/// </summary>

using namespace std;


int A = 0, K = 0; //���� ���� A�� K�� �ٲ۴�.
int MAX_NUM = 1000000; //K�� �ִ밪�� 1000000�̴� �� ���� MAX������ �����Ѵ�.
vector<int> graph(1000000, 0); //�ʱ� �ּ� �Ÿ��� �� 0�̴�.

int BFS(int start)
{
	queue<int> q;
	q.push(start);

	while ( !q.empty() )
	{
		int cur = q.front();
		q.pop();

		if ( cur == K )
		{
			return graph[cur];
		} 
		if ( cur + 1 <= MAX_NUM && graph[cur + 1] == 0)
		{
			q.push(cur + 1);
			graph[cur + 1] = graph[cur] + 1;
		}
		if ( cur * 2 <= MAX_NUM && graph[cur * 2] == 0 )
		{
			q.push(cur * 2);
			graph[cur * 2] = graph[cur] + 1;
		}
	}
}

int main(void)
{
	FastIO;

	std::cin >> A >> K;

	int minResult = BFS(A);

	std::cout << minResult << "\n";
	return 0;
}