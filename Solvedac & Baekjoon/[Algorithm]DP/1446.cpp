#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver1 ������ - DP �˰���
/// (��ӵ����� ���� < ������ ����) || ((������ ����)-(������ ����) < ������ ����) �ΰ�� ����
/// pair�� ���� 2���� �迭���� �ش� ��ġ�� ���� {key, value}�������� ������ �� �ִ�.
/// </summary>


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	vector<int> dp(10000, 10000); //�� ���̺� �̵��ؾ��� �Ÿ� üũ�ϱ�, �ſ� ū ���� �ʱ�ȭ
	vector<pair<int, int>> shortPath[10000]; //������ ���� ����
	int N(0), D(0); //������ ����, ��ӵ��� ����
	int start(0), end(0), shortPathCost(0);

	std::cin >> N >> D;
	for (int i = 0; i < N; i++)
	{
		std::cin >> start >> end >> shortPathCost;
		if (end > D || (end - start) < shortPathCost)
		{
			continue;
		}
		//������ ���� �������ٰ� �������� ���� ��ġ��, ���� �����صα�
		shortPath[end].push_back({ start, shortPathCost });
	}

	dp[0] = 0; //0���� ���°� 0����
	for (int i = 1; i <= D; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < (int)shortPath[i].size(); j++)
		{
			// ���� ������ cost�� �������� start���� + �������� ����
			int curPathCost = dp[shortPath[i][j].first] + shortPath[i][j].second;
			dp[i] = std::min(dp[i], curPathCost);
		}
	}

	std::cout << dp[D] << std::endl;
	return 0;
}