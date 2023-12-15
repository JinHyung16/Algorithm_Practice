#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 별 찍기 - 2 - 구현 알고리즘
/// for i to N 까지 돌면서
///  for j to N-1을 통해 공백 출력
///  for k to k+1을 통해 별을 출력한다.
/// 그 후 항상 "\n"을 통해 줄을 바꿔준다.
/// </summary>

int main(void)
{
	FastIO;
	int N = 0; // 별 N개
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			cout << " ";
		}

		for (int k = 0; k < k + 1; k++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}