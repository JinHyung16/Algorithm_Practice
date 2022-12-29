#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 촌수계산 - Graph 알고리즘
/// BFS를 이용한 풀이
/// 촌수 관계가 있으면 visited 값에 해당 촌수의 값에서 +1해주면 된다.
/// </summary>

using namespace std;

int n(0); // 사람의 수 n
int m(0); //부모 자식간의 관계의 개수 m

vector<vector<int>> relationships(101, vector<int>(101, 0)); //n의 범위 최대가 100이하
vector<int> visited(101, 0);

void BFS(int start, int end)
{
	queue<int> q;
	q.push(start);

	visited[start] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (relationships[cur][i] == 1 && visited[i] == 0)
			{
				//관계가 있는데 방문 안했으면 계속 촌수 증가시키기
				q.push(i);
				visited[i] = visited[cur] + 1;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int p1(0), p2(0); //서로 다른 두 사람의 번호
	int x(0), y(0); //부모 자식간의 관계를 나타내는 두 번호

	std::cin >> n;
	std::cin >> p1 >> p2;
	std::cin >> m;
	while(m--)
	{
		std::cin >> x >> y;

		//연결된 가족끼린 1로 표시
		relationships[x][y] = 1;
		relationships[y][x] = 1;
	}

	BFS(p1, p2);

	if (visited[p2] != 0)
	{
		std::cout << visited[p2] - 1 << std::endl;
	}
	else
	{
		std::cout << -1 << std::endl;
	}


	return 0;
}