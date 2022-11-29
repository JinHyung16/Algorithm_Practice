#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver1 RGB �Ÿ� - DP �˰���
/// �� �� ���� RGB�� �ϳ���, �̾��� �������� ������ X
/// �׷��ٸ� ���� ������� R,G,B��� �����ϰ�
/// ù��°���� n��° ���� �� ������ ���� �ּҰ� �Ǹ� �Ǵµ�,
/// ���� �տ��� R ����ٸ� ������ R�����ϰ� ���� �ϴ� ����.
/// </summary>

/// <summary>
/// #include<algorithm>���� �ִ� 2������ ���� �ּڰ� ��ȯ�ϴ� �Լ��ۿ� ����
/// 3��¥���� �̷��� �����ؾ� �Ѵ�.
/// </summary>
/// <param name="a"> ù��° ���� </param>
/// <param name="b"> �ι�° ���� </param>
/// <param name="c"> ����° ���� </param>
/// <returns> 3���� ������ ���� ���� intger ���� ���� </returns>
int minThree(int a, int b, int c)
{
	int minValue = std::min(a, b);
	return minValue < c ? minValue : c;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int houseCount = 0;
	int rgbCount = 3;

	std::cin >> houseCount;

	int cost = 0;
	vector<vector<int>> dp(houseCount + 1, vector<int>(rgbCount)); //r g b 3���ϱ�
	vector<vector<int>> houseCost(houseCount + 1, vector<int>(rgbCount));

	for (int i = 0; i < houseCount; i++)
	{
		for (int j = 0; j < rgbCount; j++)
		{
			//dp[i][0] = ������ ��, dp[i][1]�� �ʷϻ� ��, dp[i][2]�� �Ķ��� ������ ����
			std::cin >> dp[i][j];
			//cost���� �޸������̼�����
			houseCost[i][j] = dp[i][j];
		}
	}

	for (int i = 1; i < houseCount; i++)
	{
		//rgb �� r�����ߴ� �����ϸ� ���� ���� g�� b�߿��� get
		houseCost[i][0] = dp[i][0] + std::min(houseCost[i - 1][1], houseCost[i - 1][2]);

		//rgb �� g�����ߴ� �����ϸ� �������� r�� b�߿��� �ּҰ� get
		houseCost[i][1] = dp[i][1] + std::min(houseCost[i - 1][0], houseCost[i - 1][2]);

		//rgb �� b�����ߴ� �����ϸ� �������� r�� g�߿��� get
		houseCost[i][2] = dp[i][2] + std::min(houseCost[i - 1][0], houseCost[i - 1][1]);
	}

	cost = minThree(houseCost[houseCount - 1][0], houseCost[houseCount - 1][1], houseCost[houseCount - 1][2]);

	std::cout << cost << std::endl;


	return 0;
}