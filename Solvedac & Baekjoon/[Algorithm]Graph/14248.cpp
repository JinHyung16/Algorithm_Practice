#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ���� ���� - Graph �˰���
/// ���� �켱 Ž������ ������ �ذ��Ѵ�.
/// visited ���͸� ���� �湮�ߴ��� ���ߴ��� ������ üũ�Ѵ�.
/// ����������� DFS�� �����Ͽ�, start + graph[start]�� �湮�ϰ� �ٸ� ���� start - graph[start]�� �����Ѵ�.
/// �׷��� DFS�� �� �����ϰ� �� ��, for i to n�� ���� visited[i]�� true���� ������ �ľ��Ͽ� ����Ѵ�.
/// </summary>

using namespace std;

int n = 0; //���ٸ��� �� ����
int s = 0; //����� s

vector<int> graph;
vector<bool> visited;

void DFS(int start)
{
	if ( start < 1 || n < start )
	{
		return;
	}
	visited[start] = true;
	DFS(start + graph[start]);
	DFS(start - graph[start]);
}

int main(void)
{
	FastIO;
	std::cin >> n;
	graph.resize(n + 1, 0);
	visited.resize(n + 1, false);
	for ( int i = 1; i <= n; i++ )
	{
		std::cin >> graph[i];
	}
	std::cin >> s;

	DFS(s);

	int result = 0;
	for ( int i = 1; i <= n; i++ )
	{
		if ( visited[i] )
		{
			result++;
		}
	}
	std::cout << result << "\n";
	return 0;
}