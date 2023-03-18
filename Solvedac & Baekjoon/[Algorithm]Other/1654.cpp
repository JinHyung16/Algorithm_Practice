#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver2 ���� �ڸ��� - �̺�Ž�� �˰���
/// �ʿ��� ������ ������ N
/// ���� �� �Է¹��� ���̸� mid�� ���� �� ���� N�� ��
/// ���� N���� ũ�ų� ���ٸ� start�� mid���� �� ĭ �������� �Ű� �� �� ���̷� N���� ���� �� �ִ��� �˻�
/// ���� N���� �۴ٸ� end�� mid���� �� ĭ ������ �Ű�, �� ª�� ���̸� �̿��ϸ� N���� ���� �� �ִ��� �˻��Ѵ�.
/// �̶� ������ N�� ������ ���� int�� �ϸ� �������� long long��������
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int K(0), N(0); //������ �ִ� ������ ���� K, �ʿ��� ������ ���� N
	std::cin >> K >> N;
	vector<long long> lanCable(K);
	long long maxLength(0);
	long long resultMax(0);

	for (int i = 0; i < K; i++)
	{
		std::cin >> lanCable[i];
		maxLength = std::max(maxLength, lanCable[i]);
	}

	long long start = 1, end = maxLength, mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int cur = 0;
		for (int i = 0; i < K; i++)
		{
			cur += (lanCable[i] / mid);
		}

		if (N <= cur)
		{
			start = mid + 1;
			resultMax = std::max(resultMax, mid);
		}
		else
		{
			end = mid - 1;
		}
	}

	std::cout << resultMax << "\n";
	return 0;
}