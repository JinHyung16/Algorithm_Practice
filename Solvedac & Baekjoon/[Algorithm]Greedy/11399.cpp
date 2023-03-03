#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ATM - Greedy �˰���
/// ���� �ð��� ���� ������� �������� �����Ͽ� ���ذ��� �ȴ�.
/// ���Ҷ� ���� ���� �ִ� ������� �ɸ� ���� �ð��� (�ջ���� �ɸ� ����ð� + ���� �����ϴµ� �ɸ� �ð�)���� ��������
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //����� ��
	int totalWithdrawalTime(0); //��ü ����� �����ϴµ� �ɸ� �ð�
	std::cin >> N;

	vector<int>withdrawTime(N, 0); //�����ϴµ� �ɸ��� �ð� ���
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