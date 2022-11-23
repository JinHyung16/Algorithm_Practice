#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver4 - �׸��� �˰���
/// S = aVec[0]*bVec[0] + ... + aVec[n]*bVec[n] �� ��
/// aVec�� ��迭�Ͽ� �ּ��� S ã��
/// aVec�� ���������ؼ� ��ǻ� bVec�� ���� ū ���� ã�� mapping�ϴ� ���̴�
/// bVec�� ���������ϰ� ���������� aVec�� ���� ���Ѵٸ� �ּ� S�� �Ǵ� ��
/// </summary>


int main(void)
{
	int n(0);

	cin >> n;

	vector<int> aVec(n);
	vector<int> bVec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> aVec[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> bVec[i];
	}

	std::sort(aVec.begin(), aVec.end());
	std::sort(bVec.rbegin(), bVec.rend());

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (aVec[i] * bVec[i]);
	}

	std::cout << sum << std::endl;

	return 0;
}