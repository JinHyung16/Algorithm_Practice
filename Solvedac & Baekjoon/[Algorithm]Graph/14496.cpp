#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver2 그대, 그머가 되어 - Graph 알고리즘
/// BFS를 이용한 문제 풀이
/// vector를 입력받은 N이후 사이즈 초기화 하려면
/// resize를 이용해 N보다 +1 많게 초기화 다시해주면 된다.
/// </summary>

using namespace std;

int H(0), W(0); //그리드의 높이 H, 너비 W
vector<vector<int>> vec;
vector<bool> visited(1001, false);
vector<int> changeCnt(1001, 0);

int BFS(int start, int end)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == end)
		{
			return changeCnt[cur];
		}

		for (int i = 0; i < vec[cur].size(); i++)
		{
			int curPair = vec[cur][i];
			if (!visited[curPair])
			{
				q.push(curPair);
				visited[curPair] = true;

				changeCnt[curPair] = changeCnt[cur] + 1;
			}
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int A(0), B(0); //바꾸려는 문자 a와 b
	int N(0), M(0); //전체 문자의 수 N, 치환 가능한 문자쌍의 수 M
	
	std::cin >> A >> B;
	std::cin >> N >> M;
	vec.resize(N + 1);

	int m1, m2;
	for (int i = 0; i < M; i++)
	{
		std::cin >> m1 >> m2;
		vec[m1].push_back(m2);
		vec[m2].push_back(m1);
	}

	if (A == B)
	{
		std::cout << 0 << std::endl;
	}
	else
	{
		std::cout << BFS(A, B) << std::endl;
	}
	return 0;
}