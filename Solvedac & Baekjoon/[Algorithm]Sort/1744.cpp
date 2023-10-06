#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold4 수 묶기 - 정렬 알고리즘
/// 양수의 경우 큰 수끼리 묶어 곱한다.
/// 음수의 경우 절대값이 큰 음수끼리 묶어 곱한다.
/// 1은 묶기보다 그냥 더한다.
/// 0의 경우 음수가 홀수라면 절대값이 가장 작은 음수와 곱한다.
/// </summary>

int main(void)
{
	FastIO;

	int N = 0; //수열의 크기 N
	int input = 0;
	vector<int> positive, negative; //양수와 음수를 구분해 담아둘 배열

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (0 < input)
			positive.push_back(input);
		else
			negative.push_back(input);
	}

	sort(positive.rbegin(), positive.rend());
	sort(negative.begin(), negative.end());

	int maxSum = 0;
	if (0 < positive.size()) 
	{
		if (positive.size() % 2 != 0)
		{
			maxSum += positive[positive.size() - 1];
		}
		for (int i = 0; i < positive.size() - 1; i += 2)
		{
			if (positive[i + 1] == 1)
				maxSum += (positive[i] + positive[i + 1]);
			else if (0 < positive[i + 1])
				maxSum += (positive[i] * positive[i + 1]);
		}
	}

	if (0 < negative.size())
	{
		if (negative.size() % 2 != 0)
		{
			maxSum += negative[negative.size() - 1];
		}
		for (int i = 0; i < negative.size() - 1; i += 2)
		{
			maxSum += (negative[i] * negative[i + 1]);
		}
	}
	cout << maxSum << "\n";
	return 0;
}