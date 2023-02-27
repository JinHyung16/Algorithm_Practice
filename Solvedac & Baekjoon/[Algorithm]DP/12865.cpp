#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 ����� �賶 - DP �˰���
/// dp[i][j]�� ���� ���� i�϶� �ش� ������ ��ġ j�� �ǹ�
/// ���Ը� ��Ƴ��� �迭�� �����, ���� 1���� �����ؼ� N���� ���� �� �ֳ� �� ����.
/// ���� �� �ִٸ�, ���� ���� ������ ��ġ(dp[i-1][j])�� ���� ���ǿ��� ���� ������ ��ġ���� ���� �� ū ���� �ִ´�.
/// ���� �� ���ٸ�, dp[i][j]�� �׳� ���� ���� ������ ��ġ�� �ִ´�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0), K(0); //��ǰ�� �� N, ��ƿ �� �ִ� ���� K
	//int W(0), V(0); //�� ������ ���� W, �ش� ������ ��ġ V

	//vector���� 0���� �ʱ�ȭ�ϸ� �� vector�� 0��° index�� �˾Ƽ� 0���� �Ҵ��
	vector<vector<int>> dp(101, vector<int>(100001, 0));
	vector<int> weighVec(101, 0);
	vector<int> valueVec(101, 0);

	std::cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> weighVec[i] >> valueVec[i];
	}

	for (int w = 1; w <= N; w++)
	{
		for (int v = 1; v <= K; v++)
		{
			if (0 <= v - weighVec[w])
			{
				//���濡 ������ ���� �� �ִٸ�
				dp[w][v] = std::max(dp[w - 1][v], dp[w - 1][v - weighVec[w]] + valueVec[w]);
			}
			else
			{
				dp[w][v] = dp[w - 1][v];
			}

		}
	}

	std::cout << dp[N][K] << "\n";
	return 0;
}