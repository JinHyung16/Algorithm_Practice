#include<iostream>
#include<vector>

/// <summary>
/// Silver4 ���Ӻκ��ִ�� - DP �˰���
/// �Ǽ��� �̿��ϴ� ���� int�� �ƴ� double�� �Ѵ�.
/// cout���� �ݿø��� ���� fixed��
/// �Ҽ��� 3�ڸ������� ����ϴ� percision�� �������
/// </summary>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N(0); //������ ���� �Ǽ����� ���� N
	vector<double> dp(10000, 0.0);
	std::cin >> N;
	vector<double> vec(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> vec[i];
	}

	double maxDouble = 0.0;
	dp[0] = vec[0];

	for (int i = 1; i < N; i++)
	{
		dp[i] = std::max(vec[i], vec[i] * dp[i - 1]);
		maxDouble = std::max(maxDouble, dp[i]);
	}
	
	std::cout << fixed;
	std::cout.precision(3);
	std::cout << maxDouble << std::endl;
	return 0;
}