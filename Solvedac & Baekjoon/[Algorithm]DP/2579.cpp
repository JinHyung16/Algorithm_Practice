#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ��� ������ - DP �˰���
/// ����� 1ĭ �Ǵ� 2ĭ�� ���� �� ������, ���ӵ� �� ���� ����� ��� ������ �ȵȴ�.
/// �� �������� �����Ѵ�.
/// �׷��ٸ� ó�� ���������� 3ĭ������ max������ �־�ΰ� �� ��° ��ܺ��� dp[i]�� ����Ѵ�
/// ������ ���� ����� ������ ��ƾ��ϴ�, stairs[i]�� ������ ����� �ǹǷ�, 
/// dp[i] = max(dp[i-2]+stairs[i], dp[i-3]+stair[i-1]+stairs[i])�� ���� ū ���� ������ �ȴ�.
/// ��, �� �ǹ̴� ������ ��ܱ��� ��ĭ�� �ִ� ����, ������ ��� ���� ���� ��ܰ� ������� ���� 3ĭ�� �ִ� ���� ���ϴ� �Ŵ�
/// �� 3ĭ���̳ĸ� �� ���� ���ӵ� ����� ������ �ȵǱ� �����̴�.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	int N(0); //����� ����
	std::cin >> N;
	
	vector<int>dp(301, 0);
	vector<int> stairs(301, 0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> stairs[i];
	}

	dp[0] = stairs[0]; //������ ���
	dp[1] = std::max(stairs[1], stairs[0] + stairs[1]);
	//���������� ��ĭ �ö󰣰Ŷ�, ���������� ��ĭ �ö󰣰Ŷ� ���ؼ� ū �� �ֱ�
	dp[2] = std::max(stairs[1] + stairs[2], stairs[0] + stairs[2]);

	for (int i = 3; i < N; i++)
	{
		dp[i] = std::max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}
	std::cout << dp[N - 1] << "\n";
	return 0;
}