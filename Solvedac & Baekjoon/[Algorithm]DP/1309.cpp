#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver1 동물원 - DP 알고리즘
/// 동물들은 가로로 나란하게 배치할 수 없으므로, 1번째에 배치하면 다음 배치는 3번째 고정이다
/// 배치하는 경우의 수 dp[n] = dp[n-1] * 2 + dp[n-2]
/// 잘 생각해보면, 내가 현재 배치한 곳 기준 배치되는 곳 은 내 기준 이전이전과 + 내 이전 기준의 다음 다음으로 *2로 표시
/// </summary>

int MAX_SIZE = 100001;
int outputDivide = 9901; //문제에서 출력시 나누라는 수

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int cageSize(0);
	std::cin >> cageSize;

	vector<int> dp(MAX_SIZE, 0);
	dp[0] = 1; //1번째 배치
	dp[1] = 3; //3번째 배치

	for (int i = 2; i <= cageSize; i++)
	{
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % outputDivide;
	}

	std::cout << dp[cageSize] << std::endl;
	return 0;
}