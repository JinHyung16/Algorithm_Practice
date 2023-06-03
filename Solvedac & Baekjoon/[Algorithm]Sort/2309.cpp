#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 �ϰ� ������ - ���� �˰���
/// 7���� �����̸� ã�� �������� �����Ͽ� ����ؾ� �ϴµ�, ������ 7���� Ű�� ���� 100�̿����Ѵ�.
/// 1. ó�� 9�� Ű�� �Է¹����鼭 ��ü Ű ���� total�� �����صΰ� ������ �����Ѵ�.
/// 2. 9���� Ű�� �Է¹��� vector�� ������������ sort�Ѵ�.
/// ���� for���� ���� ���������Ͽ� �����ص� ���Ϳ��� ������ �ִ� �ΰ��� Ű�� total���� ���鼭 100�̶� �Ȱ����� ��, �� �� index���� �����ϰ� ������ 7�� Ű�� ���
/// �׸��� ���� return0���� �����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	vector<int> dwarfs(9, 0);
	int totalHeight = 0;

	for (int i = 0; i < dwarfs.size(); i++)
	{
		std::cin >> dwarfs[i];
		totalHeight += dwarfs[i];
	}

	std::sort(dwarfs.begin(), dwarfs.end());

	for (int i = 0; i < 8; i++) //���� Ž���� ������ index�̹Ƿ� ���������� �� �ʿ� ����.
	{
		for (int j = i + 1; j < 9; j++) //�� �������� ���޾� Ž���� index�� i+1���� �׻� ������ ���������� Ž���Ѵ�.
		{
			if (totalHeight - dwarfs[i] - dwarfs[j] == 100)
			{
				for (int index = 0; index < 9; index++)
				{
					if (index == i || index == j)
					{
						continue;
					}
					std::cout << dwarfs[index] << "\n";
				}
				return 0; //break�� ���� �ٱ� for���� �� �����Ƿ� return0���� ���α׷��� ������.
			}
		}
	}
	return 0;
}
