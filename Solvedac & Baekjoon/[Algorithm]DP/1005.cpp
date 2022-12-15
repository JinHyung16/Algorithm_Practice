#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

/// <summary>
/// Gold3 - DP �˰���
/// 1�� �ǹ� �ϼ� -> 2, 3�� �Ǽ� ���� -> 2,3�� �Ѵ� �ϼ��ؾ� 4�� �Ǽ� ����
/// �Ǽ��� �ǹ��� ������ �߿��ϴ�. ���� ����ó�� 2,3���� ���� ��ġ�ε� 4���� �Ǽ� ������
/// 3�� �� 4���� �տ��� ���� �Ǽ��� ���� ������ �ǹ��� ������ �ޱ� �����̴�
/// �迭�� �ʱ�ȭ�� for������ memset�� �̿��ϴ°� �� ������ ������� header�� cstring�� �����ִ�
/// </summary>


using namespace std;

const int MAX = 1001;
vector<int> buildGraph[MAX]; //graph ���·� ���´�

int buildDegree[MAX]; //�Ǽ��� �ǹ��� ����
int buildTime[MAX];
int dp[MAX]; //index��° �Ǽ��ؾ��� �ּ� �ð� ����

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
	int factoryN(0), ruleK(0); //�ǹ��� n�� �ǹ��� ���� ��Ģ ���� k
	int buildW(0); //�¸��ϱ� ���� �Ǽ��ؾ� �� �ǹ� ��ȣ w

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