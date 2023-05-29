#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ��� - DP �˰���
/// dp[i]�� i�ϱ��� ������ �� ���� �ִ� ������ �ǹ��Ѵ�.
/// dp[i]���� i�Ͽ��� �ɸ��� �ð������� dp���� i�Ͽ� ���� ���� vs i�� ������ �ʰ� �� ������ ���� �������� ���Ͽ� ū ���� �־�д�.
/// N�Ϻ��� �Ųٷ� ���鼭 �ִ��� �־�д�.
/// 
/// �̶�, i�Ͽ��� ����� �ɸ��� �ð��� ��ģ ���� N�� ������ ����� �� �� ���⿡, dp[i]�� dp[i+1]���� �����ϰ� continue�ع�����.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //���ϴ� �Ⱓ N
	int maxRevenue(-1); //�ִ� ����

	vector<pair<int, int>> job;
	vector<int> dp(20, 0);
	std::cin >> N;

	for(int i = 0; i < N; i++)
	{
		int time(0), price(0);
		std::cin >> time >> price;
		job.push_back(make_pair(time, price));
	}

	for (int i = N - 1; 0 <= i; i--)
	{
		if (N < i + job[i].first)
		{
			dp[i] = dp[i + 1]; //dp[i]�� i+1���� �־�ΰ� ����������.
			continue;
		}
		dp[i] = std::max(dp[i + job[i].first] + job[i].second, dp[i + 1]);
	}
	
	for (int i = 0; i < N; i++)
	{
		maxRevenue = std::max(maxRevenue, dp[i]);
	}
	std::cout << maxRevenue << "\n";
	return 0;
}
