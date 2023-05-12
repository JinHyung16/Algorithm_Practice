#include<iostream>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ���� - DP �˰���
/// ��͸� �̿��ϸ� ���� Ŀ������ stackoverflow�� �Ͼ �� �ִ�.
/// ���� dp�� �̿��� �޸������� �̿��� �޸� ������ �ذ��Ѵ�.
/// dp[n][r]�� �̿��� �ذ��Ѵ�.
/// AddNum�� ����, ū �� ���� ���ϴ� �Լ��� ����� �̿��Ѵ�.
/// </summary>

using namespace std;

int N(0), M(0); //nCm�� �ǹ�
string dp[101][101];

string AddNum(string a, string b)
{
	string result = "";
	if (b.length() < a.length())
	{
		while (a.length() != b.length())
		{
			b = '0' + b;
		}
	}
	else
	{
		while (a.length() != b.length())
		{
			a = '0' + a;
		}
	}

	int sum = 0;
	for (int i = a.length() - 1; 0 <= i; i--)
	{
		sum += a[i] - '0';
		sum += b[i] - '0';

		result = to_string(sum % 10) + result;
		if (10 <= sum)
		{
			sum = 1;
		}
		else
		{
			sum = 0;
		}
	}

	if (sum == 1)
	{
		return '1' + result;
	}
	return result;
}

void Combination()
{
	dp[0][0] = "1";
	dp[1][0] = dp[1][1] = "1";
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (i == j || j == 0)
			{
				dp[i][j] = "1";
			}
			else
			{
				dp[i][j] = AddNum(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}
}

int main(void)
{
	FastIO;

	std::cin >> N >> M;
	Combination();

	std::cout << dp[N][M] << "\n";
	return 0;
}