#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 가장 긴 바이토닉 부분 수열 - DP 알고리즘
/// 증가하는 부분수열 중 가장 긴 부분 수열 + 감소하는 부분수열 중 가장 긴 부분 수열을 찾으면 된다.
/// 이때 dpIncrease[i] + dpDecrease[i] - 1을 해서 두 부분수열의 길이 합에서 1을 빼는데, 이유는 중복되는 숫자 제거다.
/// ex) 1, 2, 3 부분수열 길이와 3, 2, 1에서 중복되는 원소 3이 있으므로 이를 제거
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //수열 A의 크기 N
	std::cin >> N;
	vector<int> sequence(N + 1, 0);
	vector<int> dpIncrease(N + 1, 0);
	vector<int> dpDecrease(N + 1, 0);
	sequence[0] = 0;

	for(int i = 1; i <= N; i++)
	{
		std::cin >> sequence[i];
		dpIncrease[i] = 1;
		dpDecrease[i] = 1;
	}

	//증가하는 수열 중 가장 길이가 긴 부분 수열
	for(int i = 1; i <= N; i++)
	{
		for(int j = i + 1; j <= N; j++)
		{
			if(sequence[i] < sequence[j] && dpIncrease[j] < dpIncrease[i] + 1)
			{
				dpIncrease[j] = dpIncrease[i] + 1;
			}
		}
	}

	for ( int i = N; 1 <= i; i-- )
	{
		for ( int j = i - 1; 1 <= j; j-- )
		{
			if ( sequence[i] < sequence[j] && dpDecrease[j] < dpDecrease[i] + 1 )
			{
				dpDecrease[j] = dpDecrease[i] + 1;
			}
		}
	}

	int maxLength = 1;
	for(int i = 1; i <= N; i++)
	{
		maxLength = std::max(maxLength, dpIncrease[i] + dpDecrease[i] - 1);
	}
	std::cout << maxLength << "\n";
	return 0;
}