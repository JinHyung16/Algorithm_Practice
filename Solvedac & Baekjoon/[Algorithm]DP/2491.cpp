#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver4 ���� - DP �˰���
/// dp�� �ٽ��� �ѹ��� �������, ��� �� ���� �� �������
/// �׸��� �ѹ� �Ҷ� �� ������ �ִٸ� �װɷ� �����س���!
/// vector�ʱ�ȭ �� n������ 1���� ���� �ʱ�ȭ �ϴ°�, ���� �� +1�� ���������̴�.
/// �� n��° ���� ���� �� n+1���� �񱳰� �ʿ��ؼ���.
/// ó���� ���� for�� ���ȴµ�, �����غ��� �׷� �ʿ䰡 ����
/// </summary>


int main(void)
{
	//�� ��� �ӵ� up
	ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n = 0;
	std::cin >> n;

	vector<int> sequenceVec(n + 1, n + 1);
	int maxLength = 1;

	for (int i = 0; i < n; i++)
	{
		std::cin >> sequenceVec[i];
	}

	//�ּ� ���̴� 1(���θ� ������ ���)
	int upCount = 1; //�������� �� �� ����
	int downCount = 1; //�������� �� �� ����

	for (int i = 0; i < n - 1; i++)
	{
		if (sequenceVec[i] <= sequenceVec[i + 1])
		{
			upCount++;
		}
		else
		{
			upCount = 1;
		}

		if (sequenceVec[i] >= sequenceVec[i + 1])
		{
			downCount++;
		}
		else
		{
			downCount = 1;
		}

		int maxCount = std::max(upCount, downCount);
		maxLength = std::max(maxLength, maxCount);
	}

	std::cout << maxLength << std::endl;

	return 0;
}