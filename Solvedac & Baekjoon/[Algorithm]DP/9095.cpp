#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver3 1,2,3 ���ϱ� - DP �˰���
/// �迭�� �����ϰ�, �迭[index]���� index�� �ǹ� ������ �߿�
/// index�� 1,2,3�� ���ؼ� �ش� index���� ���鶧 �����̰�
/// �迭[index]�� �� �� ������ �����س��� ���̴�.
/// </summary>


int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int testCase = 0;
	std::cin >> testCase;
	int num = 0;
	for (int i = 0; i < testCase; i++)
	{
		std::cin >> num;
		vector<int> dp(num+1, 0); //dp�� �ش� index�� 1,2,3�� ���ؼ� ���� �� �ִ� ��� �� ����
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		
		for (int j = 4; j <= num; j++)
		{
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		std::cout << dp[num] << std::endl;;
	}
	
	return 0;
}