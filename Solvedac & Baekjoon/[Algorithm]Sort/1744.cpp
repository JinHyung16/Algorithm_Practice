#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Gold4 �� ���� - ���� �˰���
/// ����� ��� ū ������ ���� ���Ѵ�.
/// ������ ��� ���밪�� ū �������� ���� ���Ѵ�.
/// 1�� ���⺸�� �׳� ���Ѵ�.
/// 0�� ��� ������ Ȧ����� ���밪�� ���� ���� ������ ���Ѵ�.
/// </summary>

int main(void)
{
	FastIO;

	int N = 0; //������ ũ�� N
	int input = 0;
	vector<int> positive, negative; //����� ������ ������ ��Ƶ� �迭

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