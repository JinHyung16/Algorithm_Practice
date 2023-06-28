#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 예산 - 이분 탐색 알고리즘
/// 예산 전체를 입력받은 후, 오름차순으로 정렬해놓는다.
/// 
/// ex) N = 4, M = 485, budget = {110, 120, 140, 150} 문제 예시를 통해 정렬한 모습까지 나열하면 다음과 같다.
/// left = 0, right = 150, mid = (left+right)/2= 75다
/// for i to N sum += std::min(budget[i], mid)를 통해 가장 작은 값만을 찾아 더해간다.
/// sum값이 총 예산을 넘으면 left를 이동시키고, 아니라면 right를 이동시키면서 mid값을 갱신하고 다시 찾아간다.
/// 이렇게 left값이 right보다 작거나 같을때까지 돌면서 상한액을 찾아간다.
/// </summary>

using namespace std;

vector<int> budget;

int main(void)
{
	FastIO;

	int N = 0; //지방의 수 및 예산 요청 개수 N
	int M = 0; //총 예산 M

	std::cin >> N;
	for(int i = 0; i < N; i++)
	{
		int input = 0;
		std::cin >> input;
		budget.push_back(input);
	}
	std::cin >> M;

	std::sort(budget.begin(), budget.end());

	int left = 0;
	int right = budget[budget.size() - 1];
	int limitBudget = 0;
	while(left <= right)
	{
		int budgetSum = 0;
		int mid = (left + right) / 2;
		for(int i = 0; i < N; i++)
		{
			budgetSum += std::min(budget[i], mid);
		}

		if(budgetSum <= M)
		{
			limitBudget = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	std::cout << limitBudget << "\n";
	return 0;
}