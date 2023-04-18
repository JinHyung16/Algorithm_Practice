#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 2*n 타일링 2 - DP 알고리즘
/// DP의 핵심은 점화식을 구해야한다.
/// 주어진 타일은 1*2, 2*1, 2*2 이렇게 있다.
/// n=i일때 dp[i]는 2*i 타일 사이즈를 채우는 경우의 수다
/// n=1일때 2*1 -> 2*1 -> 1가지
/// n=2일때 2*2 -> 2*2 or 1*2 2개 or 2*1 2개-> 1 + 1 + 1 = 3가지
/// n=3일때 2*3 -> dp[2]를 채우고 남은 2*1영역을 2*1 1개사용 or 1*2 2개 사용 -> 3 + 1 + 1 = 5가지
/// n=4일때 2*4 -> dp[3]에다가 2*1을 추가 or dp[2]의 경우에서 남은 2*2 영역 채우는 경우 -> 5 + 3 + 3 = 11가지
/// n=5일때 2*5 -> dp[4]에다가 2*1을 추가 or dp[3]의 경우에서 남은 2*2 영역 채우는 경우 -> 11 + 5 + 5 = 21가지
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //2*N의 크기의 직사각형
	std::cin >> N;
	vector<int> dp(1001, 0); //나누기 10007한 나머지로 저장한다.
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= N; i++)
	{
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
	}

	std::cout << dp[N] << "\n";
	return 0;
}