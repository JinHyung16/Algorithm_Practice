#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver2 ���� �� �����ϴ� �κ� ���� - DP �˰���
/// dp[i] = j�� i�� index������ �ִ� ���̴� j�� �ǹ��Ѵ�.
/// 
/// ex) A = {10, 20, 10, 20, 20, 10}�� ����
/// for i=0 to A.size();
///  for j=0 to i;
/// �̷� ���� ���� for���� ���鼭
/// if(�迭[i] < �迭[j] && dp[i] < dp[j]+1)
///  dp[i] = dp[j]+1�� ���ش�.
/// </summary>




int main(void)
{
	FastIO;

	int N = 0; //���� A�� ũ�� N
	vector<int> A, dp;
	
	cin >> N;
	A.resize(N, 0);
	dp.resize(N, 0);
	for ( int i = 0; i < N; i++ )
	{
		cin >> A[i];
	}

	for ( int i = 0; i < N; i++ )
	{
		dp[i] = 1;
		for ( int j = 0; j < i; j++ )
		{
			if ( A[i] < A[j] && dp[i] < dp[j] + 1 )
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	sort(dp.rbegin(), dp.rend());
	cout << dp[0] << "\n";
	return 0;
}