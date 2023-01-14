#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 결혼식 - Graph 알고리즘
/// BFS를 통한 문제 풀이
/// 문제 설명을 보면, 결국 친구는 상근이 즉 1번부터 연결되어야 친구다
/// </summary>

using namespace std;

int N(0), M(0); //상근이 동기의 수 N, 리스트 길이 M
vector<vector<int>> friends(502, vector<int>(502, 0));
vector<bool> visited(502, false);
int inviteCnt(0);

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur != 1)
		{
			//상근이의 직접적인 친구가 아니라면
			for (int i = 2; i <= N; i++)
			{
				//상근이 친구를 기준으로 딱 1번만 보면 된다
				if (friends[cur][i] == 1 && !visited[i])
				{
					visited[i] = true;
					inviteCnt++;
					continue;
				}
			}
		}
		else
		{
			//상근이의 직접적인 친구라면
			for (int i = 1; i <= N; i++)
			{
				//1은 상근이로 상근이 기준부터 보면 된다
				if (friends[cur][i] == 1 && !visited[i])
				{
					visited[i] = true;
					q.push(i);
					inviteCnt++;
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int u(0), v(0);

	std::cin >> N;
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		std::cin >> u >> v;
		//서로 관계가 있으면 1로 표시
		friends[u][v] = 1;
		friends[v][u] = 1;
	}

	BFS(1);
	std::cout << inviteCnt << std::endl;

	return 0;
}