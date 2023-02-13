#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 �˹ٻ� ��ȣ - Greedy �˰���
/// ���� �� �ִ� ���� �ִ��� ���� ���� ���� �ִ� ����� �����ָ� �ȴ�.
/// (���� ��� - 1)�̹Ƿ� 1���� 0, 2���� 1, 3���� 2 �̷������� ����� ���´�.
/// ���� �� ����� �迭�� index�� 0, 1, 2 ... ����ϸ� �ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //�� �ִ� ����� �� N
	vector<int> tipVec(100001, 0); //tip�� ������ �迭
	long long tipSum(0); //���� �� �ִ� �ִ� tip��

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> tipVec[i];
	}
	
	//tip�� ���� ū ������� �����ϱ�
	std::sort(tipVec.begin(), tipVec.end(), std::greater<>());

	for (int i = 0; i < N; i++)
	{
		if (0 < tipVec[i] - i)
		{
			//i�� (���-1)�� �ǹ�, ������� tip�ִµ� �����
			tipSum += (tipVec[i] - i);
		}
	}

	std::cout << tipSum << "\n";
	
	return 0;
}