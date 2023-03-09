#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 LCS - 문자열 알고리즘
/// 1. 문제에서 주어 예시로 LCS를 표로 그리는데 조건은 같은 문자가 나오면 이전 LCS길이(왼쪽위 즉 대각선)+1
/// 2. 다른 문자가 나오면 비교한 문가가 포함되어 있는 직전 LCS (위쪽값과 왼쪽 값 중) 큰 값을 넣는다.
/// 위 두개의 조건을 식으로 쓰면 1)dp[i][j] = dp[i-1][j-1]+1 / 2)dp[i][j] = max(dp[i-1][j], dp[i][j-1])
/// ACAYKP와 CAPCAK의 LCS는 ACAK가 되는 이유는 다음과 같다. (선택된 부분에 *을 붙여 표시)
/// 1)4가 가장 먼저 나오는 지점 선택 -> K
/// 2)4-1=3, 3이 가장 먼저 나오는 지점 선택 (ACAYKP에서 P보다 A가 더 앞쪽으로 3이 먼저 나왔다 판단,CAPCAK도 A일때 3이 먼저 나옴) -> A
/// 3)4-2=2, 2가 가장 먼저 나오는 지점 선택 (ACAYKP에선 C가 먼저고, CAPCAK에서도 C가 먼저 나오니 해당 부분 선택) -> C
/// 4)4-3=1, 1이 가장 먼저 나오는 지점 선택 -> A
/// 따라서 ACAYKP와 CAPCAK의 LCS는 ACAK고 가장 큰 값을 출력하니 4다.
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

vector<vector<int>> dp(1001, vector<int>(1001, 0)); //LCS의 최대 길이를 저장한다.

int main(void)
{
	FastIO;

	string s1, s2;
	std::cin >> s1;
	std::cin >> s2;

	//1부터 시작인 이유는 i-1과 j-1때문에 음수 나오니깐
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