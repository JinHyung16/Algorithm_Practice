#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

/// <summary>
/// Gold3 - DP 알고리즘
/// 1번 건물 완성 -> 2, 3번 건설 가능 -> 2,3번 둘다 완성해야 4번 건설 가능
/// 건설할 건물의 순서도 중요하다. 문제 예시처럼 2,3번은 같은 위치인데 4번의 건설 시작은
/// 3번 즉 4번의 앞에서 가장 건설이 오래 끝나는 건물에 영향을 받기 때문이다
/// 배열들 초기화시 for문보단 memset을 이용하는게 더 빠르니 사용하자 header는 cstring에 속해있다
/// </summary>


using namespace std;

const int MAX = 1001;
vector<int> buildGraph[MAX]; //graph 형태로 나온다

int buildDegree[MAX]; //건설할 건물의 순서
int buildTime[MAX];
int dp[MAX]; //index번째 건설해야할 최소 시간 저장

void ResetGlobal()
{
	memset(buildDegree, 0, sizeof(buildDegree));
	memset(buildTime, 0, sizeof(buildTime));
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < MAX; i++)
	{
		buildGraph[i].clear();
	}
}

void FindShortestTime(int n)
{
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (buildDegree[i] == 0)
		{
			dp[i] = buildTime[i];
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < buildGraph[cur].size(); i++)
		{
			int next = buildGraph[cur][i];
			buildDegree[next]--;
			dp[next] = std::max(dp[next], dp[cur] + buildTime[next]);
			if (buildDegree[next] == 0)
			{
				q.push(next);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int testCase(0);
	int factoryN(0), ruleK(0); //건물수 n과 건물간 순서 규칙 개수 k
	int buildW(0); //승리하기 위해 건설해야 할 건물 번호 w

	std::cin >> testCase;

	for(int i = 0; i < testCase; i++)
	{
		ResetGlobal();

		std::cin >> factoryN >> ruleK;
		for (int j = 1; j <= factoryN; j++)
		{
			std::cin >> buildTime[j];
		}

		int u, v;
		for (int j = 0; j < ruleK; j++)
		{
			cin >> u >> v;
			buildGraph[u].push_back(v);
			buildDegree[v]++;
		}

		std::cin >> buildW;

		FindShortestTime(factoryN);
		std::cout << dp[buildW] << std::endl;
	}
	return 0;
}