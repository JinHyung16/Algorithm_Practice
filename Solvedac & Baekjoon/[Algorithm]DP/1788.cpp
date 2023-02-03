#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 �Ǻ���ġ ���� Ȯ�� - DP �˰���
/// ó�� Ǯ���� �� Ʋ�ȴ�. ������ �����ʿ��� �߻��ߴ�.
/// F(0)=0, F(-1)=1, F(-2)=-1, F(-3)=2, F(-4)=-1
/// �̷������� �������� ������ ¦���� ���� Ȧ���� ����� ���Դ� ���̴�.
/// 
/// F(N)����� 1, ������ -1, 0�̸� 0 ����ϱ�
/// </summary>

using namespace std;

const int divideNum = 1000000000;

int main(void)
{
	FastIO;
	
	vector<int> dp(1000001);
	dp[0] = 0;
	dp[1] = 1;

	int N(0), input(0);
	std::cin >> input;
	if (input < 0)
	{
		N = input * (-1); //����� ����� �ֱ�
	}
	else
	{
		N = input;
	}

	
	for (int i = 2; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % divideNum;
	}

	dp[N] = dp[N] % divideNum;

	if (N == 0)
	{
		std::cout << N << "\n" << N;
		return 0;
	}
	else if (input < 0)
	{
		//�����϶� ���밪�� ¦���� ����
		if (N % 2 == 0)
		{
			std::cout << -1 << "\n" << dp[N];
			return 0;
		}
	}

	//��� �Ǵ� �����ε� ���밪�� Ȧ���� ���
	std::cout << 1 << "\n" << dp[N];

	return 0;
}