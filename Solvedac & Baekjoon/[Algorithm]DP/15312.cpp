#include<iostream>
#include<vector>
#include<string>

/// <summary>
/// Silver5 �̸� ���� - DP �˰���
/// �� ����� �̸��� �޾�, ȹ�� ���鼭 int�� �����صд�.
/// �׷��� ������� ������ �迭���� i��°�� i+1��° ȹ���� ���ϰ� 10���� ������
/// �������� ���̰� 2���Ǹ� ����Ѵ�.
/// </summary>

using namespace std;

vector<int> stroke = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string A, B; //�������� ���� �̸� A, �׳��� ���� �̸� B
	std::cin >> A >> B;

	vector<int> dp;
	for (int i = 0; i < A.size(); i++)
	{
		dp.push_back(stroke[A[i] - 'A']);
		dp.push_back(stroke[B[i] - 'A']);
	}

	while (true)
	{
		vector<int> temp;
		for (int i = 0; i < dp.size() - 1; i++)
		{
			temp.push_back((dp[i] + dp[i + 1]) % 10);
		}

		//��� �� �ڸ� ���
		dp = temp;
		if (dp.size() == 2)
		{
			std::cout << dp[0] << dp[1] << std::endl;
			return 0;
		}
	}
	return 0;
}