#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 계단 오르기 - DP 알고리즘
/// 계단은 1칸 또는 2칸씩 오를 수 있으며, 연속된 세 개의 계단은 모두 밟으면 안된다.
/// 단 시작점은 제외한다.
/// 그렇다면 처음 시작점에서 3칸까지는 max값으로 넣어두고 세 번째 계단부터 dp[i]를 계산한다
/// 마지막 도착 계단은 무조건 밟아야하니, stairs[i]는 마지막 계단이 되므로, 
/// dp[i] = max(dp[i-2]+stairs[i], dp[i-3]+stair[i-1]+stairs[i])를 비교해 큰 값을 넣으면 된다.
/// 즉, 이 의미는 마지막 계단기준 두칸전 최대 값과, 마지막 계단 기준 이전 계단과 이전계단 기준 3칸전 최대 값을 비교하는 거다
/// 왜 3칸전이냐면 세 개의 연속된 계단은 밟으면 안되기 때문이다.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	int N(0); //계단의 개수
	std::cin >> N;
	
	vector<int>dp(301, 0);
	vector<int> stairs(301, 0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> stairs[i];
	}

	dp[0] = stairs[0]; //시작점 계단
	dp[1] = std::max(stairs[1], stairs[0] + stairs[1]);
	//시작점에서 두칸 올라간거랑, 시작점에서 한칸 올라간거랑 비교해서 큰 값 넣기
	dp[2] = std::max(stairs[1] + stairs[2], stairs[0] + stairs[2]);

	for (int i = 3; i < N; i++)
	{
		dp[i] = std::max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}
	std::cout << dp[N - 1] << "\n";
	return 0;
}