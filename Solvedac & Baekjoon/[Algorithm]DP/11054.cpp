#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold4 ���� �� ������� �κ� ���� - DP �˰���
/// �����ϴ� �κм��� �� ���� �� �κ� ���� + �����ϴ� �κм��� �� ���� �� �κ� ������ ã���� �ȴ�.
/// �̶� dpIncrease[i] + dpDecrease[i] - 1�� �ؼ� �� �κм����� ���� �տ��� 1�� ���µ�, ������ �ߺ��Ǵ� ���� ���Ŵ�.
/// ex) 1, 2, 3 �κм��� ���̿� 3, 2, 1���� �ߺ��Ǵ� ���� 3�� �����Ƿ� �̸� ����
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //���� A�� ũ�� N
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

	//�����ϴ� ���� �� ���� ���̰� �� �κ� ����
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