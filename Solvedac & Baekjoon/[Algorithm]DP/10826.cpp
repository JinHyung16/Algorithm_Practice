#include<iostream>
#include<string>
#include<algorithm>

/// <summary>
/// Silver5 �Ǻ���ġ �� 4 - DP �˰���
/// dp[i]�� i��° ������ �Ǻ���ġ ���� �ǹ��Ѵ�.
/// ��ͷ� Ǯ�� �Լ��� ���ÿ� ��� ���̰�, �ð��� �����ɸ���.
/// �Լ��� �̿��� �޸������̼��ϸ鼭 Ǯ���
/// n�� �ִ밡 10000�̹Ƿ�, �Ǻ���ġ ����ϸ� ���� �ſ� Ŀ����
/// long long���� �ذ��ϰų� string���� Ǯ��
/// string���� ���Ұ��, carry�߻����� üũ�ϸ鼭 �������
/// </summary>

using namespace std;

string Fibonacci(string a, string b)
{
	int num(0);
	int carry(0);

	string result;
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());

	while (a.length() != b.length())
	{
		if (a.length() < b.length())
		{
			a += '0';
		}
		else
		{
			b += '0';
		}
	}

	for (int i = 0; i < a.length(); i++)
	{
		num = (a[i] - '0' + b[i] - '0' + carry) % 10;
		result += std::to_string(num);
		carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
	}

	if (carry != 0)
	{
		result += std::to_string(carry);
	}

	std::reverse(result.begin(), result.end());
	return result;
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string dp[10010];

	int N(0); //n��° �Ǻ���ġ ��
	std::cin >> N;
	
	dp[0] = '0';
	dp[1] = '1';

	for (int i = 2; i <= N; i++)
	{
		dp[i] = Fibonacci(dp[i - 1], dp[i - 2]);
	}

	std::cout << dp[N] << std::endl;
	return 0;
}