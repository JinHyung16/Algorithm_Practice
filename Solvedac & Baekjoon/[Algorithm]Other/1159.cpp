#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 �� ��� - ���ڿ� �˰���
/// ���� ���ĺ� �ҹ����̴�, �̸��� �ո� int�� ��ȯ�� �̸� index�� ����ϴ� vector�� ���� ������Ų��.
/// ���ĺ� �ҹ��� a�� -97�ϸ� 0�� �ǹ�, 0���ٰ� +97�ϸ� char�� a�� ���´�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N(0); //������ �� N
	string name; //���� �̸� ���� ����

	bool canPlay = false; //���� ������ �ִ��� üũ�ϴ� bool
	char lastName = ' '; //�⼱ ������ ���� ����ϱ� ���� ����
	vector<int> lastNameCnt(26, 0); //a~z���� ������� ���� ������ �����ϴ� �迭

	std::cin >> N;
	while (N--)
	{
		std::cin >> name;
		lastNameCnt[name[0] - 97]++; //�ش� ���ĺ��� ���ڷ� �ٲ� index��ȣ�� ���� ������Ű��
	}

	for (int i = 0; i < lastNameCnt.size(); i++)
	{
		if (5 <= lastNameCnt[i])
		{
			canPlay = true;
			lastName = i + 97;
			std::cout << lastName;
		}
	}

	if (!canPlay)
	{
		std::cout << "PREDAJA" << "\n";
	}
	return 0;
}