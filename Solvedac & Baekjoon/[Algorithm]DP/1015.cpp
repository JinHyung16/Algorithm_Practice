#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 수열 정렬 - 정렬 알고리즘
/// B[P[i]] = A[i]다
/// 입력으로 주어지는건 A[i]다.
/// 
/// 예제를 보면 A={2,3,1} 이고 출력 P={1,2,0}이다
/// B[P[i]]=A[i]이므로,
/// A[0] = 2 = B[P[0]], A[1] = 3 = B[P[1]], A[2] = 1 = B[P[2]] 다
/// 이를 이용해 해결한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0; //배열 A의 크기 N
	std::cin >> N;
	
	vector<pair<int, int>> dp;
	for ( int i = 0; i < N; i++ )
	{
		int ai = 0;
		std::cin >> ai;
		dp.push_back(make_pair(ai, i)); //Ai의 값과, index 값을 넣어둔다.
	}

	std::sort(dp.begin(), dp.end());
	vector<int> P(N, 0);
	for ( int i = 0; i < N; i++ )
	{
		P[dp[i].second] = i; //Ai의 index의 i값을 넣는다.
	}

	for ( int i = 0; i < P.size(); i++ )
	{
		std::cout << P[i] << " ";
	}

	return 0;
}