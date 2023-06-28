#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ���� - �̺� Ž�� �˰���
/// ���� ��ü�� �Է¹��� ��, ������������ �����س��´�.
/// 
/// ex) N = 4, M = 485, budget = {110, 120, 140, 150} ���� ���ø� ���� ������ ������� �����ϸ� ������ ����.
/// left = 0, right = 150, mid = (left+right)/2= 75��
/// for i to N sum += std::min(budget[i], mid)�� ���� ���� ���� ������ ã�� ���ذ���.
/// sum���� �� ������ ������ left�� �̵���Ű��, �ƴ϶�� right�� �̵���Ű�鼭 mid���� �����ϰ� �ٽ� ã�ư���.
/// �̷��� left���� right���� �۰ų� ���������� ���鼭 ���Ѿ��� ã�ư���.
/// </summary>

using namespace std;

vector<int> budget;

int main(void)
{
	FastIO;

	int N = 0; //������ �� �� ���� ��û ���� N
	int M = 0; //�� ���� M

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