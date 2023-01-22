#include<iostream>
#include<vector>
#include<string>

/// <summary>
/// Silver5 이름 궁합 - DP 알고리즘
/// 두 사람의 이름을 받아, 획을 빼면서 int로 저장해둔다.
/// 그렇게 순서대로 저장한 배열에서 i번째와 i+1번째 획수를 더하고 10으로 나눈뒤
/// 마지막에 길이가 2가되면 출력한다.
/// </summary>

using namespace std;

vector<int> stroke = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string A, B; //종민이의 영어 이름 A, 그녀의 영어 이름 B
	std::cin >> A >> B;

	vector<int> dp;
	for (int i = 0; i < A.size(); i++)
	{
		dp.push_back(stroke[A[i] - 'A']);
		dp.push_back(stroke[B[i] - 'A']);
	}

	while (true)
	{
		vector<int> temp;
		for (int i = 0; i < dp.size() - 1; i++)
		{
			temp.push_back((dp[i] + dp[i + 1]) % 10);
		}

		//결과 두 자리 출력
		dp = temp;
		if (dp.size() == 2)
		{
			std::cout << dp[0] << dp[1] << std::endl;
			return 0;
		}
	}
	return 0;
}