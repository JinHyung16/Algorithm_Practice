#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver4 ���� ���� - ���� �˰���
/// n�� ������ �� ������ start������ end������ �˰� ������
/// n���� ���� start������ vec[i-1] + 1�������� n����
/// n���� ������ end������ vec[i] - 1�� n���� end��������
/// �� ���� ���� (n-start) * (end-n+1) + (end-n)
/// </summary>

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int vecSize = 0;
	std::cin >> vecSize;

	vector<int> vec(vecSize);
	int n = 0;
	int cnt = 0;
	bool IsSame = false;
	int start = 0;
	int end = 0;

	for (int i = 0; i < vecSize; i++)
	{
		std::cin >> vec[i];
	}
	std::cin >> n;

	std::sort(vec.begin(), vec.end());
	for (int i = 0; i < vecSize; i++)
	{
		if (vec[i] == n)
		{
			IsSame = true;
		}

		if (n < vec[i])
		{
			start = vec[i - 1] + 1;
			end = vec[i] - 1;
			break;
		}
	}
	cnt = ((n - start) * (end - n + 1)) + (end - n);
	if (IsSame)
	{
		std::cout << 0 << std::endl;
	}
	else
	{
		std::cout << cnt << std::endl;
	}
	return 0;
}