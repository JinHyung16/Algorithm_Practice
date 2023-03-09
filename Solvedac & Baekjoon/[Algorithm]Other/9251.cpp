#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 LCS - ���ڿ� �˰���
/// 1. �������� �־� ���÷� LCS�� ǥ�� �׸��µ� ������ ���� ���ڰ� ������ ���� LCS����(������ �� �밢��)+1
/// 2. �ٸ� ���ڰ� ������ ���� ������ ���ԵǾ� �ִ� ���� LCS (���ʰ��� ���� �� ��) ū ���� �ִ´�.
/// �� �ΰ��� ������ ������ ���� 1)dp[i][j] = dp[i-1][j-1]+1 / 2)dp[i][j] = max(dp[i-1][j], dp[i][j-1])
/// ACAYKP�� CAPCAK�� LCS�� ACAK�� �Ǵ� ������ ������ ����. (���õ� �κп� *�� �ٿ� ǥ��)
/// 1)4�� ���� ���� ������ ���� ���� -> K
/// 2)4-1=3, 3�� ���� ���� ������ ���� ���� (ACAYKP���� P���� A�� �� �������� 3�� ���� ���Դ� �Ǵ�,CAPCAK�� A�϶� 3�� ���� ����) -> A
/// 3)4-2=2, 2�� ���� ���� ������ ���� ���� (ACAYKP���� C�� ������, CAPCAK������ C�� ���� ������ �ش� �κ� ����) -> C
/// 4)4-3=1, 1�� ���� ���� ������ ���� ���� -> A
/// ���� ACAYKP�� CAPCAK�� LCS�� ACAK�� ���� ū ���� ����ϴ� 4��.
/// 0	A	C	A	Y	K	P
/// 0	0	0	0	0	0	0
/// C	0	1 	1	1	1	1
/// A	*1	1	2	2	2	2
/// P	1	1	2	2	2	3
/// C	1	*2	2	2	2	3
/// A	1	2	*3	3	3	3
/// K	1	2	3	3	*4	4
/// </summary>

using namespace std;

vector<vector<int>> dp(1001, vector<int>(1001, 0)); //LCS�� �ִ� ���̸� �����Ѵ�.

int main(void)
{
	FastIO;

	string s1, s2;
	std::cin >> s1;
	std::cin >> s2;

	//1���� ������ ������ i-1�� j-1������ ���� �����ϱ�
	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	std::cout << dp[s1.length()][s2.length()] << "\n";
	return 0;
}