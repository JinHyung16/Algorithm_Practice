#include<iostream>
#include<vector>
#include<string>


using namespace std;

/// <summary>
/// Silver5 ������ - greedy �˰���
/// ex)11001 �Է½� s[1]=1, s[2]=0�̴�.
/// �� �̷��� �ٸ� ��찡 ������ ��, ���� ���ڰ� 0���� 1���� ���� �ش� ���� ī����
/// �׷��� s[3]�� s[4] �񱳼� ���� index�� 3�ε� ���� �ٸ���, ī���� �ϴ� ���� �κ��� 0�϶���
/// �̴� �� 2~3��° index�� ��� counting�ϴ� �Ͱ� ������ ȿ����
/// </summary>


int main(void)
{
	string s;
	vector<int> counting(2, 0); //0�� 1 ī���� �ϱ�

	std::cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != s[i + 1])
		{
			if (s[i] == '0')
			{
				counting[0]++;
			}
			else if (s[i] == '1')
			{
				counting[1]++;
			}
		}
	}

	if (counting[0] < counting[1])
	{
		std::cout << counting[0] << std::endl;
	}
	else
	{
		std::cout << counting[1] << std::endl;
	}

	return 0;
}