#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 �Ӹ���� ����� - Greedy �˰���
/// �Ӹ������ �Ųٷ� �о ����� �����Ͱ� ������ �ǹ�
/// �Ӹ������ Ȧ���� ���ĺ��� 2���̻� ������ ���� �� ����.
/// ������ �ҹ��ڴ� -37�ؼ� �ش� ���ĺ��� ī��Ʈ�� �������״ٸ�
/// �빮�ڴ� +'A'���·� ����ϸ�ȴ�.
/// 1)�� ���� �̸� ������� ��ġ
/// 2)�� Ȧ������ �߾ӿ� ��ġ
/// 3)�� �������� �̸� ��ġ�ϴ� ����̴�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string name;
	string palindromeName;
	vector<int> alphabet(26, 0);

	std::cin >> name;
	for (int i = 0; i < name.size(); i++)
	{
		alphabet[name[i] - 'A']++;
	}

	int oddAlphaCnt(0);
	for (int i = 0; i < alphabet.size(); i++)
	{
		if (alphabet[i] % 2 == 1)
		{
			oddAlphaCnt++;
		}
	}

	if (2 <= oddAlphaCnt)
	{
		//Ȧ������ ���ĺ��� 2�� �̻��̸� �Ӹ������ ���� �� ����.
		std::cout << "I'm Sorry Hansoo" << "\n";
		return 0;
	}

	//1) A���� Z���� ���� ���ĺ��� ����/2��ŭ ���ĺ� �����ش�
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < alphabet[i]/2; j++)
		{
			palindromeName += (i + 'A');
		}
	}

	//2) ���� Ȧ������ ���ĺ��� �Ӹ�������� ���� ���� �߾ӿ� ��ġ
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] % 2 == 1)
		{
			palindromeName += (i + 'A');
		}
	}

	//3) Z���� A���� ���� ���ĺ��� ����/2��ŭ ���ĺ� �����ش�
	for (int i = 25; 0 <= i; i--)
	{
		for (int j = 0; j < alphabet[i] / 2; j++)
		{
			palindromeName += (i + 'A');
		}
	}

	std::cout << palindromeName << "\n";
	return 0;
}