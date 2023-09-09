#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 �ʱ��� ���� - �׷����̷� �˰���
/// ����� �׷����� ���� �Ÿ� C�� ������ �� �ְ� pair�� �̿��Ѵ�.
/// �ִ� �Ÿ��� �����ϴµ�, ���� ���� ������ �Ÿ��� �̹� ���ٸ� ������ �н��Ͽ� �ð��� �����Ѵ�.
/// </summary>

using namespace std;

int N = 0;
vector<pair<int, long long>> graph[5010]; //a�� b�� ����


long long DFS(int start, long long distance)
{
	long long result = 0;
	for ( int i = 0; i < graph[start].size(); i++ )
	{
		if ( graph[start][i].first == distance )
		{
			continue;
		}
		result = std::max(result, DFS(graph[start][i].first, start) + graph[start][i].second);
	}
	return result;
}

int main(void)
{
	FastIO;

	std::cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		int A = 0, B = 0, C = 0;
		std::cin >> A >> B >> C;
		graph[A].push_back(make_pair(B, C));
		graph[B].push_back(make_pair(A, C));
	}

	std::cout << DFS(1, -1) << "\n";
	return 0;
}