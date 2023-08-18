#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ���� ���� - ���� �˰���
/// B[P[i]] = A[i]��
/// �Է����� �־����°� A[i]��.
/// 
/// ������ ���� A={2,3,1} �̰� ��� P={1,2,0}�̴�
/// B[P[i]]=A[i]�̹Ƿ�,
/// A[0] = 2 = B[P[0]], A[1] = 3 = B[P[1]], A[2] = 1 = B[P[2]] ��
/// �̸� �̿��� �ذ��Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //�迭 A�� ũ�� N
	std::cin >> N;
	
	vector<pair<int, int>> dp;
	for ( int i = 0; i < N; i++ )
	{
		int ai = 0;
		std::cin >> ai;
		dp.push_back(make_pair(ai, i)); //Ai�� ����, index ���� �־�д�.
	}

	std::sort(dp.begin(), dp.end());
	vector<int> P(N, 0);
	for ( int i = 0; i < N; i++ )
	{
		P[dp[i].second] = i; //Ai�� index�� i���� �ִ´�.
	}

	for ( int i = 0; i < P.size(); i++ )
	{
		std::cout << P[i] << " ";
	}

	return 0;
}