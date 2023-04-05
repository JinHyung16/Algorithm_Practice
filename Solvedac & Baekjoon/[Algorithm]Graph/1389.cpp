#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 케빈 베이컨의 6단계 법칙 - 그래프 알고리즘
/// BFS 또는 플로이드-와샬 알고리즘을 이용해 풀 수 있다.
/// 
/// BFS를 이용해 i번째 사람을 기준으로 친구인지 아닌지 판단해
/// BFS에서 i번째와 친구인걸 queue에 넣고, 해당 queue에서 다시 친구인걸 찾아서
/// 최종적으로 처음 들어온 i -> i의 친구 -> i의 친구의 친구 -> ... 이런식으로 i의 케빈 베이컨의 수를 찾는다.
/// i번째 기준 찾은 케빈 베이컨의 수의 합을 최소값과 비교해가면서 i~N까지의 사람중 케빈 베이컨의 수가 최소인 사람을 찾아 true로 반환
/// 최종 mian()에서 실행한 result = i는 BFS에서 찾은 케빈 베이컨의 수가 가장 작은 사람을 의미
/// </summary>

using namespace std;

int N(0), M(0); //유저의 수 N, 친구의 수 M
vector<vector<int>> relation(101, vector<int>(101, 0));
vector<bool> visited(101, false);
vector<int> KevinCntVec(101, 0);
int kevinMin = 987654321;


void Reset()
{
	for (int i = 0; i < 101; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < 101; i++)
	{
		KevinCntVec[i] = 0;
	}
}
bool BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i] && relation[cur][i] == 1)
			{
				visited[i] = true;
				KevinCntVec[i] = KevinCntVec[cur] + 1;
				q.push(i);
			}
		}
	}

	//ex) 1번이 처음 들어오면 문제에서 1->3->2니깐 여기선 1->3 1번 + 3->2 1번 이렇게 합해서 2를 만든다.
	int kvSum = 0;
	for (int i = 1; i <= N; i++)
	{
		kvSum += KevinCntVec[i];
	}

	if (kvSum < kevinMin)
	{
		kevinMin = kvSum;
		return true;
	}
	return false;
}

int main(void)
{
	FastIO;

	std::cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a(0), b(0);
		std::cin >> a >> b;
		relation[a][b] = 1;
		relation[b][a] = 1;
	}

	int result(0);

	for (int i = 1; i <= N; i++)
	{
		//i번째 친구인지 아닌지를 판단한다.
		if (BFS(i))
		{
			result = i;
		}
		Reset();
	}

	std::cout << result << "\n";
	return 0;
}