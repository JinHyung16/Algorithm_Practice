#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver1 ������ - DP �˰���
/// �������� ���η� �����ϰ� ��ġ�� �� �����Ƿ�, 1��°�� ��ġ�ϸ� ���� ��ġ�� 3��° �����̴�
/// ��ġ�ϴ� ����� �� dp[n] = dp[n-1] * 2 + dp[n-2]
/// �� �����غ���, ���� ���� ��ġ�� �� ���� ��ġ�Ǵ� �� �� �� ���� ���������� + �� ���� ������ ���� �������� *2�� ǥ��
/// </summary>

int MAX_SIZE = 100001;
int outputDivide = 9901; //�������� ��½� ������� ��

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int cageSize(0);
	std::cin >> cageSize;

	vector<int> dp(MAX_SIZE, 0);
	dp[0] = 1; //1��° ��ġ
	dp[1] = 3; //3��° ��ġ

	for (int i = 2; i <= cageSize; i++)
	{
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % outputDivide;
	}

	std::cout << dp[cageSize] << std::endl;
	return 0;
}