#include<iostream>
#include<vector>
#include<string>

/// <summary>
/// Gold3 알 수 없는 문장 - DP 알고리즘
/// 각 문장의 단어들의 length만큼 잘라서 계속 비교하면서 정답을 찾는다
/// </summary>

using namespace std;

const int alphabetNum = 26; //알파벳 A~Z까시 개수

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	string input; //주어진 문장
	int n(0); //단어의 개수

	std::cin >> input;
	std::cin >> n;

	vector<string> stringVec(n);
	vector<int> dp(input.length() + 1, 999999);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		string temp;
		std::cin >> temp;
		stringVec[i] = temp;
	}

	for (int i = 0; i < input.length(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			string temp = stringVec[j];
			int sizeTemp = temp.size();

			if (sizeTemp > i + 1)
			{
				continue;
			}

			vector<int> count(alphabetNum);
			vector<int> counts(alphabetNum);
			for (char c : temp)
			{
				count[c - 'a']++;
			}
			for (int k = 0; k < sizeTemp; k++)
			{
				counts[input[i - k] - 'a']++;
			}

			int test = 1;
			for (int k = 0; k < alphabetNum; k++)
			{
				if (count[k] == counts[k])
				{
					test = 1;
				}
				else
				{
					test = 0;
					break;
				}
			}

			if (test == 0)
			{
				continue;
			}

			int value = 0;
			for (int k = 0; k < sizeTemp; k++)
			{
				if (input[i + 1 - sizeTemp + k] != temp[k])
				{
					value += 1;
				}
			}

			dp[i + 1] = min(dp[i + 1], dp[i + 1 - sizeTemp] + value);
		}
	}

	if (dp[input.length()] == 999999)
	{
		std::cout << -1 << std::endl;
	}
	else
	{
		std::cout << dp[input.length()] << std::endl;
	}
	return 0;
}