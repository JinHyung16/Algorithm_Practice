#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ATM - Greedy 알고리즘
/// 인출 시간이 작은 사람부터 오름차순 정렬하여 더해가면 된다.
/// 더할때 줄을 서고 있는 사람들이 걸린 인출 시간은 (앞사람이 걸린 인출시간 + 내가 인출하는데 걸린 시간)임을 생각하자
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //사람의 수
	int totalWithdrawalTime(0); //전체 사람이 인출하는데 걸린 시간
	std::cin >> N;

	vector<int>withdrawTime(N, 0); //인출하는데 걸리는 시간 담기
	for (int i = 0; i < N; i++)
	{
		std::cin >> withdrawTime[i];
	}

	std::sort(withdrawTime.begin(), withdrawTime.end());

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			totalWithdrawalTime += withdrawTime[j];
		}
	}

	std::cout << totalWithdrawalTime << "\n";
	return 0;
}